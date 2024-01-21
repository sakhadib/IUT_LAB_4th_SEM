-- Task - 1
SELECT * FROM instructor where dept_name = 'Biology';


-- Task - 2
SELECT course.course_id, course.title
FROM takes JOIN course ON takes.course_id = course.course_id
WHERE takes.ID = '73492';

-- Task - 3
SELECT student.name, student.dept_name
FROM student
WHERE student.ID IN (
    SELECT takes.ID
    FROM takes
    WHERE takes.course_id IN (
        SELECT course.course_id
        FROM course
        WHERE course.dept_name = 'Comp. Sci.'
    )
);

-- Task - 4
SELECT student.name
FROM student
WHERE student.ID IN (
    SELECT takes.ID
    FROM takes
    WHERE takes.course_id = 'CS-101' AND takes.semester = 'Spring' AND takes.year = 2018
);

-- Task - 5
SELECT student.name
FROM student
WHERE student.ID IN (
    SELECT takes.ID
    FROM takes
    WHERE takes.course_id LIKE 'CS%'
    GROUP BY takes.ID
    HAVING COUNT(*) = (
        SELECT MAX(course_count)
        FROM (
            SELECT COUNT(*) as course_count
            FROM takes
            WHERE takes.course_id LIKE 'CS%'
            GROUP BY takes.ID
        )
    )
);

-- Task - 6
SELECT student.name
FROM student
WHERE student.ID IN (
    SELECT takes.ID
    FROM takes
    JOIN teaches ON takes.course_id = teaches.course_id AND takes.sec_id = teaches.sec_id AND takes.semester = teaches.semester AND takes.year = teaches.year
    GROUP BY takes.ID
    HAVING COUNT(DISTINCT teaches.ID) >= 3
);


-- Task - 7
SELECT course.title, takes.course_id, takes.sec_id, COUNT(*) as num_enrollments
FROM takes
JOIN course ON takes.course_id = course.course_id
GROUP BY takes.course_id, takes.sec_id, course.title
HAVING COUNT(*) > 0
ORDER BY num_enrollments ASC
FETCH FIRST 1 ROWS ONLY;


-- Task - 8
SELECT instructor.name, instructor.dept_name, COALESCE(student_count, 0) AS student_count
FROM instructor
LEFT JOIN (
    SELECT advisor.i_ID, COUNT(*) AS student_count
    FROM advisor
    GROUP BY advisor.i_ID
) advisor_count ON instructor.ID = advisor_count.i_ID;

-- Task - 9
SELECT s.name, s.dept_name
FROM student s
WHERE (
  SELECT COUNT(*) 
  FROM takes t
  WHERE t.ID = s.ID
) > (
  SELECT COUNT(*) / COUNT(DISTINCT ID)
  FROM takes
);


-- Task - 10
INSERT INTO student (ID, name, dept_name, tot_cred)
SELECT ID, name, dept_name, 0
FROM instructor where ID <> '76543';

-- Task - 11

select student.id from
student join instructor on student.id = instructor.id;


-- Task - 12
UPDATE student s
SET tot_cred = (
  SELECT SUM(c.credits)
  FROM takes t
  JOIN course c ON t.course_id = c.course_id
  WHERE t.ID = s.ID
);


-- Task - 13
UPDATE instructor i
SET salary = (
  SELECT COUNT(*) * 10000
  FROM teaches t
  WHERE t.ID = i.ID
);


-- Task - 14
SELECT s.ID, s.name, AVG(gp.points * c.credits) as CPI
FROM student s
LEFT JOIN takes t ON s.ID = t.ID
LEFT JOIN course c ON t.course_id = c.course_id
LEFT JOIN (
  SELECT 'A' as grade, 10 as points FROM dual UNION ALL
  SELECT 'B', 8 FROM dual UNION ALL
  SELECT 'C', 6 FROM dual UNION ALL
  SELECT 'D', 4 FROM dual UNION ALL
  SELECT 'F', 0 FROM dual
) gp ON t.grade = gp.grade
GROUP BY s.ID, s.name;



