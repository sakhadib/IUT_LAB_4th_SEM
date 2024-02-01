SET SERVEROUTPUT ON;

-- Task 1
BEGIN
DBMS_output.Put_line('Adib');
END
/

-- Task 2
BEGIN
ID = '&id';
DBMS_output.Put_line('length is : ' || length(ID));
END     

-- Task 3 (a)
DECLARE
    CURSOR lab_3_C1 IS
        SELECT I.ID, I.NAME, I.SALARY, SUM(C.CREDITS) AS TOTAL_CREDITS
        FROM INSTRUCTOR I
        JOIN teaches T ON T.ID = I.ID
        JOIN course C ON C.COURSE_ID = T.COURSE_ID
        GROUP BY I.ID, I.NAME, I.SALARY;
    
    NEW_SALARY INSTRUCTOR.SALARY%TYPE;

BEGIN
    FOR REC IN lab_3_C1 LOOP
        NEW_SALARY := 9000 * REC.TOTAL_CREDITS;
        IF NEW_SALARY != REC.SALARY THEN
                UPDATE INSTRUCTOR
                SET SALARY = CASE
                WHEN NEW_SALARY<=29000 THEN 30000
                ELSE NEW_SALARY 
                END
                WHERE ID = REC.ID;
        ELSE    
            DBMS_OUTPUT.PUT_LINE(REC.NAME );
        END IF;
    END LOOP;

    COMMIT;
END;
/


-- TASK 3 (B)
DECLARE
    CURSOR lab_3_C2 IS
        SELECT C.TITLE, S.NAME
        FROM COURSE c
        JOIN prereq P ON C.COURSE_ID = P.COURSE_ID
        JOIN TAKES T ON P.prereq_id = T.COURSE_ID
        JOIN STUDENT S ON T.ID = S.ID;

BEGIN
    FOR REC IN lab_3_C2 LOOP
        DBMS_OUTPUT.PUT_LINE('Course Title: ' || rec.title || ', Student Name: ' || rec.name);
    END LOOP;
END;
/


-- task 4 (c)




-- TASK 3 (D)
DECLARE
    CURSOR lab_3_C4 IS
        SELECT I.ID, I.NAME, I.dept_name
        FROM INSTRUCTOR i
        LEFT JOIN ADVISOR A ON I.ID = A.i_ID
        WHERE A.I_ID IS NULL;

    STUDENT_ID STUDENT.ID%TYPE;

BEGIN
    FOR REC IN lab_3_C4 LOOP
        SELECT ID INTO STUDENT_ID
        FROM STUDENT
        WHERE DEPT_NAME = REC.DEPT_NAME AND ID NOT IN (SELECT S_ID FROM ADVISOR) AND ROWNUM = 1
        ORDER BY tot_cred ASC;
        

        IF STUDENT_ID IS NOT NULL THEN
            INSERT INTO ADVISOR (S_ID, I_ID) VALUES (STUDENT_ID, REC.ID);
        ELSE
            DBMS_OUTPUT.PUT_LINE('NO STUDENTS ASSIGNED TO : ' || REC.NAME);
        END IF;
    END LOOP;

    COMMIT;

EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('NO STUDENT AVAILABLE');

END;
/


DECLARE
    CURSOR c_instructor IS
        SELECT i.ID, i.name, i.dept_name
        FROM instructor i
        LEFT JOIN advisor a ON i.ID = a.i_ID
        WHERE a.i_ID IS NULL
        ORDER BY i.dept_name;
        
    CURSOR c_student IS
        SELECT s.ID, s.name, s.dept_name, s.tot_cred
        FROM student s
        LEFT JOIN advisor a ON s.ID = a.s_ID
        WHERE a.s_ID IS NULL
        ORDER BY s.dept_name, s.tot_cred;
        
    instructor_id instructor.ID%TYPE;
    instructor_name instructor.name%TYPE;
    instructor_dept instructor.dept_name%TYPE;

    student_id student.ID%TYPE;
    student_name student.name%TYPE;
    student_dept student.dept_name%TYPE;
    student_tot_cred student.tot_cred%TYPE;

BEGIN
    FOR i_rec IN c_instructor LOOP
        instructor_id := i_rec.ID;
        instructor_name := i_rec.name;
        instructor_dept := i_rec.dept_name;
        
        FOR s_rec IN c_student LOOP
            student_id := s_rec.ID;
            student_name := s_rec.name;
            student_dept := s_rec.dept_name;
            student_tot_cred := s_rec.tot_cred;
            
            IF instructor_dept = student_dept THEN
                INSERT INTO advisor VALUES (student_id, instructor_id);
                DBMS_OUTPUT.PUT_LINE('Student ' || student_name || ' assigned to Instructor ' || instructor_name);
                EXIT;
            END IF;
        END LOOP;
    END LOOP;
    
    FOR i_rec IN c_instructor LOOP
        instructor_id := i_rec.ID;
        instructor_name := i_rec.name;
        instructor_dept := i_rec.dept_name;
        
        
        DBMS_OUTPUT.PUT_LINE('Instructor ' || instructor_name || ' still does not have any students assigned to them.');
        
    END LOOP;
END;
/
