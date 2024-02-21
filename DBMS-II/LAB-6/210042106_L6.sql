-- Task 1
-- sequences
CREATE SEQUENCE biology_seq
    START WITH 1
    INCREMENT BY 1
    CACHE 10;

CREATE SEQUENCE comp_sci_seq
    START WITH 1
    INCREMENT BY 1
    CACHE 10;

CREATE SEQUENCE elec_eng_seq
    START WITH 1
    INCREMENT BY 1
    CACHE 10;

CREATE SEQUENCE finance_seq
    START WITH 1
    INCREMENT BY 1
    CACHE 10;

CREATE SEQUENCE history_seq
    START WITH 1
    INCREMENT BY 1
    CACHE 10;

CREATE SEQUENCE music_seq
    START WITH 1
    INCREMENT BY 1
    CACHE 10;

CREATE SEQUENCE physics_seq
    START WITH 1
    INCREMENT BY 1
    CACHE 10;


-- function
CREATE FUNCTION generate_student_id (p_dept_name IN VARCHAR2)
RETURN VARCHAR2 IS
  v_dept_id VARCHAR2(1);
  v_seq_num NUMBER;
  v_student_id VARCHAR2(5);

BEGIN
    CASE p_dept_name
        WHEN 'Biology' THEN v_dept_id := '1';
        WHEN 'Comp. Sci.' THEN v_dept_id := '2';
        WHEN 'Elec. Eng.' THEN v_dept_id := '3';
        WHEN 'Finance' THEN v_dept_id := '4';
        WHEN 'History' THEN v_dept_id := '5';
        WHEN 'Music' THEN v_dept_id := '6';
        WHEN 'Physics' THEN v_dept_id := '7';
        ELSE RAISE_APPLICATION_ERROR(-2000, 'Invalid department name');
    END CASE;

    CASE p_dept_name
        WHEN 'Biology' THEN 
            v_seq_num := biology_seq.NEXTVAL;
        WHEN 'Comp. Sci.' THEN 
            v_seq_num := comp_sci_seq.NEXTVAL;
        WHEN 'Elec. Eng.' THEN 
            v_seq_num := elec_eng_seq.NEXTVAL;
        WHEN 'Finance' THEN 
            v_seq_num := finance_seq.NEXTVAL;
        WHEN 'History' THEN 
            v_seq_num := history_seq.NEXTVAL;
        WHEN 'Music' THEN 
            v_seq_num := music_seq.NEXTVAL;
        WHEN 'Physics' THEN 
            v_seq_num := physics_seq.NEXTVAL;

        ELSE RAISE_APPLICATION_ERROR(-2000, 'Invalid department name');

    END CASE;

    v_student_id := v_dept_id || LPAD(TO_CHAR(v_seq_num), 4, '0');

    RETURN v_student_id;
END generate_student_id;


-- TASK 2
DECLARE
    v_dept_name student.dept_name%TYPE;
    v_old_id student.ID%TYPE;
    v_new_id student.ID%TYPE;

CURSOR c_students IS
    SELECT dept_name, id
    FROM student
    ORDER BY dept_name, name;

BEGIN
    OPEN c_students;

    LOOP
        FETCH c_students INTO v_dept_name, v_old_id;
        EXIT WHEN c_students%NOTFOUND;

        v_new_id := generate_student_id(v_dept_name);

        UPDATE student
        set id = v_new_id
        WHERE id = v_old_id;
    END LOOP;

    CLOSE c_students;
END;


-- Task 3
CREATE TRIGGER trg_gen_stu_id
BEFORE INSERT ON student
FOR EACH ROW
BEGIN
    :new.id := generate_student_id(:new.dept_name);
END;
/


-- Task 4
CREATE TRIGGER trg_update_cred
AFTER INSERT ON takes
FOR EACH ROW

DECLARE
    v_credits course.credits%TYPE;
BEGIN
    SELECT credits INTO v_credits
    FROM course
    WHERE course_id = :new.course_id;

    UPDATE student
    SET tot_cred = tot_cred + v_credits
    WHERE id = :new.id;
END;
/
