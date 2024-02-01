SET SERVEROUTPUT ON;

-- Task 1
Begin
DBMS_output.Put_line('Adib');
end
/

-- Task 2
Begin
ID = '&id';
DBMS_output.Put_line('length is : ' || length(ID));
end
/

-- Task 3 (a)
DECLARE 
    CURSOR c1 IS
        SELECT i.ID, i.name, i.salary, SUM(c.credits) as total_credits
        FROM instructor i
        JOIN teaches t ON i.ID = t.ID
        JOIN course c ON t.course_id = c.course_id
        GROUP BY i.ID, i.name, i.salary;

    new_salary instructor.salary%TYPE;
BEGIN
    FOR rec IN c1 LOOP
        new_salary := 9000 * rec.total_credits;

        IF new_salary != rec.salary THEN
            UPDATE instructor
            SET salary = new_salary
            WHERE ID = rec.ID;
        ELSE
            DBMS_OUTPUT.PUT_LINE('Salary remains unchanged for: ' || rec.name);
        END IF;
    END LOOP;

    COMMIT;
END;
/


-- Task 3 (b)
DECLARE 
    CURSOR c1 IS
        SELECT c.title, s.name
        FROM course c
        JOIN prereq p ON c.course_id = p.course_id
        JOIN takes t ON p.prereq_id = t.course_id
        JOIN student s ON t.ID = s.ID;

BEGIN
    FOR rec IN c1 LOOP
        DBMS_OUTPUT.PUT_LINE('Course Title: ' || rec.title || ', Student Name: ' || rec.name);
    END LOOP;
END;
/


-- Task 3 (c)
DECLARE 
    student_name student.name%TYPE := &student_name;
    CURSOR c1 IS
        SELECT ts.day, ts.start_hr || ':' || ts.start_min as start_time, 
               ts.end_hr || ':' || ts.end_min as end_time, 
               s.course_id, c.title, s.building, s.room_number
        FROM student st
        JOIN takes t ON st.ID = t.ID
        JOIN section s ON t.course_id = s.course_id AND t.sec_id = s.sec_id
        JOIN time_slot ts ON s.time_slot_id = ts.time_slot_id
        JOIN course c ON s.course_id = c.course_id
        WHERE st.name = student_name
        ORDER BY 
            CASE ts.day
                WHEN 'Monday' THEN 1
                WHEN 'Tuesday' THEN 2
                WHEN 'Wednesday' THEN 3
                WHEN 'Thursday' THEN 4
                WHEN 'Friday' THEN 5
                WHEN 'Saturday' THEN 6
                WHEN 'Sunday' THEN 7
            END,
            ts.start_hr,
            ts.start_min;

BEGIN
    FOR rec IN c1 LOOP
        DBMS_OUTPUT.PUT_LINE('<' || rec.day || '>');
        DBMS_OUTPUT.PUT_LINE('<' || rec.start_time || ' - ' || rec.end_time || '>');
        DBMS_OUTPUT.PUT_LINE('<' || rec.course_id || ' - ' || rec.title || '>');
        DBMS_OUTPUT.PUT_LINE('<' || rec.building || ' - ' || rec.room_number || '>');
        DBMS_OUTPUT.PUT_LINE(' ');
    END LOOP;
END;
/



-- Task 3 (d)
DECLARE 
    CURSOR c1 IS
        SELECT i.ID, i.name, i.dept_name
        FROM instructor i
        LEFT JOIN advisor a ON i.ID = a.i_ID
        WHERE a.i_ID IS NULL;

    student_id student.ID%TYPE;
BEGIN
    FOR rec IN c1 LOOP
        SELECT ID INTO student_id
        FROM student
        WHERE dept_name = rec.dept_name AND ID NOT IN (SELECT s_ID FROM advisor)
        ORDER BY tot_cred ASC
        LIMIT 1;

        IF student_id IS NOT NULL THEN
            INSERT INTO advisor (s_ID, i_ID) VALUES (student_id, rec.ID);
        ELSE
            DBMS_OUTPUT.PUT_LINE('No students assigned to: ' || rec.name);
        END IF;
    END LOOP;

    COMMIT;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No students available for assignment.');
END;
/



-- Task 3 (e)
DECLARE 
    dept_name department.dept_name%TYPE;
    min_id instructor.ID%TYPE;
    avg_salary instructor.salary%TYPE;
    new_id instructor.ID%TYPE;
    new_instructor instructor%ROWTYPE;
BEGIN
    SELECT dept_name INTO dept_name
    FROM student
    GROUP BY dept_name
    ORDER BY COUNT(*) DESC
    FETCH FIRST ROW ONLY;

    SELECT MIN(ID) INTO min_id FROM instructor;

    SELECT AVG(salary) INTO avg_salary FROM instructor WHERE dept_name = dept_name;

    new_id := TO_CHAR(TO_NUMBER(min_id) - 1);

    INSERT INTO instructor (ID, name, dept_name, salary)
    VALUES (new_id, 'John Doe', dept_name, avg_salary);

    SELECT * INTO new_instructor FROM instructor WHERE ID = new_id;

    DBMS_OUTPUT.PUT_LINE('Instructor Information:');
    DBMS_OUTPUT.PUT_LINE('ID: ' || new_instructor.ID);
    DBMS_OUTPUT.PUT_LINE('Name: ' || new_instructor.name);
    DBMS_OUTPUT.PUT_LINE('Department Name: ' || new_instructor.dept_name);
    DBMS_OUTPUT.PUT_LINE('Salary: ' || new_instructor.salary);

    COMMIT;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No data found.');
    WHEN DUP_VAL_ON_INDEX THEN
        DBMS_OUTPUT.PUT_LINE('Duplicate value on index.');
END;
/


