-- Task 1
BEGIN
DBMS_output.Put_line('bravo');
END;
/

-- Task 2
SELECT M.MOV_COUNTRY, G.GEN_TITLE, COUNT(*) AS GEN_COUNT
FROM MOVIE M
JOIN MTYPE MT ON M.MOV_ID = MT.MOV_ID
JOIN GENRES G ON MT.GEN_ID = G.GEN_ID
GROUP BY M.MOV_COUNTRY, G.GEN_TITLE
HAVING COUNT(*) >= ALL (
  SELECT COUNT(*)
  FROM MOVIE M2
  JOIN MTYPE MT2 ON M2.MOV_ID = MT2.MOV_ID
  JOIN GENRES G2 ON MT2.GEN_ID = G2.GEN_ID
  WHERE M2.MOV_COUNTRY = M.MOV_COUNTRY
  GROUP BY G2.GEN_TITLE
);





-- Task 3
SELECT DISTINCT D.DIR_FIRSTNAME, D.DIR_LASTNAME
FROM (
  SELECT DIR_ID, AVG_REV_STARS, RANK() OVER (ORDER BY AVG_REV_STARS DESC) AS RANK
  FROM (
    SELECT DIR_ID, AVG(REV_STARS) AS AVG_REV_STARS
    FROM MOVIE
    JOIN RATING ON MOVIE.MOV_ID = RATING.MOV_ID
    JOIN DIRECTION ON MOVIE.MOV_ID = DIRECTION.MOV_ID
    GROUP BY DIR_ID
  )
) R
JOIN DIRECTOR D ON R.DIR_ID = D.DIR_ID
WHERE RANK IN (2, 3, 5);


-- Task 4
CREATE OR REPLACE PROCEDURE top_rated_actors(p_year NUMBER, p_top_n NUMBER) IS
  TYPE actor_rating IS RECORD (
    firstname ACTOR.ACT_FIRSTNAME%TYPE,
    lastname ACTOR.ACT_LASTNAME%TYPE,
    avg_rating NUMBER
  );
  TYPE actor_rating_table IS TABLE OF actor_rating INDEX BY PLS_INTEGER;
  l_actor_ratings actor_rating_table;
  l_counter NUMBER := 0;
BEGIN

  FOR rec IN (
    SELECT ACT_FIRSTNAME, ACT_LASTNAME, AVG(REV_STARS) AS AVG_RATING
    FROM ACTOR
    JOIN CASTS ON ACTOR.ACT_ID = CASTS.ACT_ID
    JOIN MOVIE ON CASTS.MOV_ID = MOVIE.MOV_ID
    JOIN RATING ON MOVIE.MOV_ID = RATING.MOV_ID
    WHERE EXTRACT(YEAR FROM MOV_RELEASEDATE) = p_year
    GROUP BY ACT_FIRSTNAME, ACT_LASTNAME
    ORDER BY AVG_RATING DESC
  )
  LOOP
    l_counter := l_counter + 1;
    EXIT WHEN l_counter > p_top_n;
    DBMS_OUTPUT.PUT_LINE('First Name: ' || rec.ACT_FIRSTNAME || ', Last Name: ' || rec.ACT_LASTNAME || ', Average Rating: ' || rec.AVG_RATING);
  END LOOP;
END top_rated_actors;



-- Task 5
CREATE OR REPLACE TRIGGER check_genre_participation
AFTER INSERT ON CASTS
FOR EACH ROW
DECLARE
  l_actor_genre_count NUMBER;
  l_total_genre_count NUMBER;
  l_participation_ratio NUMBER;
BEGIN

  SELECT COUNT(DISTINCT GEN_ID)
  INTO l_actor_genre_count
  FROM CASTS
  JOIN MTYPE ON CASTS.MOV_ID = MTYPE.MOV_ID
  WHERE ACT_ID = :NEW.ACT_ID
  AND GEN_ID NOT IN (
    SELECT GEN_ID
    FROM CASTS C
    JOIN MTYPE M ON C.MOV_ID = M.MOV_ID
    WHERE C.ACT_ID = :NEW.ACT_ID
    AND C.MOV_ID <> :NEW.MOV_ID
  );

  select count(*)
  into l_total_genre_count
  from genres;

  l_participation_ratio := l_actor_genre_count / l_total_genre_count;

  DBMS_OUTPUT.Put_line('PR : ' || TO_CHAR(l_participation_ratio));


EXCEPTION
    when others THEN
        DBMS_OUTPUT.Put_line('Error : ' || SQLERRM);

END check_genre_participation;




-- Task 6

  -- Find the reviewer's given rating who has reviewed the most number of the same movies as the given reviewer
CREATE OR REPLACE FUNCTION SM(p_reviewer_id NUMBER, p_movie_id NUMBER)
RETURN NUMBER IS
  l_rating NUMBER;
BEGIN

  SELECT REV_STARS
  INTO l_rating
  FROM (
    SELECT REV_ID, COUNT(*) AS shared_movie_count
    FROM RATING
    WHERE MOV_ID IN (
      SELECT MOV_ID
      FROM RATING
      WHERE REV_ID = p_reviewer_id
    )
    AND REV_ID <> p_reviewer_id
    GROUP BY REV_ID
    ORDER BY shared_movie_count DESC
  ) R
  JOIN RATING ON R.REV_ID = RATING.REV_ID
  WHERE MOV_ID = p_movie_id
  AND ROWNUM = 1;

  RETURN l_rating;
EXCEPTION
  WHEN NO_DATA_FOUND THEN
    RETURN NULL;
END SM;


-- Find the reviewer's rating who has reviewed the highest number of movies of the same genre
CREATE OR REPLACE FUNCTION SG(p_reviewer_id NUMBER, p_movie_id NUMBER)
RETURN NUMBER IS
  l_rating NUMBER;
  l_genre_id NUMBER;
BEGIN

  SELECT GEN_ID
  INTO l_genre_id
  FROM MTYPE
  WHERE MOV_ID = p_movie_id;

  
  SELECT REV_STARS
  INTO l_rating
  FROM (
    SELECT REV_ID, COUNT(*) AS genre_movie_count
    FROM RATING
    JOIN MTYPE ON RATING.MOV_ID = MTYPE.MOV_ID
    WHERE GEN_ID = l_genre_id
    AND REV_ID <> p_reviewer_id
    GROUP BY REV_ID
    ORDER BY genre_movie_count DESC
  ) R
  JOIN RATING ON R.REV_ID = RATING.REV_ID
  WHERE MOV_ID = p_movie_id
  AND ROWNUM = 1;

  RETURN l_rating;
EXCEPTION
  WHEN NO_DATA_FOUND THEN
    RETURN NULL;
END SG;


-- Finding the reviewer's rating who has the closest avg rating
CREATE OR REPLACE FUNCTION ASM(p_reviewer_id NUMBER, p_movie_id NUMBER)
RETURN NUMBER IS
  l_avg_rating NUMBER;
  l_closest_reviewer_id NUMBER;
  l_rating NUMBER;
BEGIN

  SELECT AVG(REV_STARS)
  INTO l_avg_rating
  FROM RATING
  WHERE REV_ID = p_reviewer_id;

  SELECT REV_ID
  INTO l_closest_reviewer_id
  FROM (
    SELECT REV_ID, ABS(AVG(REV_STARS) - l_avg_rating) AS rating_difference
    FROM RATING
    WHERE REV_ID <> p_reviewer_id
    GROUP BY REV_ID
    ORDER BY rating_difference
  )
  WHERE ROWNUM = 1;


  SELECT REV_STARS
  INTO l_rating
  FROM RATING
  WHERE REV_ID = l_closest_reviewer_id
  AND MOV_ID = p_movie_id;

  RETURN l_rating;
EXCEPTION
  WHEN NO_DATA_FOUND THEN
    RETURN NULL;
END ASM;




