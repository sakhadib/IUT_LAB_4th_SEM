-- Task 1
CREATE TABLESPACE TBS1 DATAFILE 'tbs1.dbf' SIZE 1M EXTENT MANAGEMENT LOCAL AUTOALLOCATE;
CREATE TABLESPACE TBS2 DATAFILE 'tbs2.dbf' SIZE 1M EXTENT MANAGEMENT LOCAL AUTOALLOCATE;
CREATE TABLESPACE TBS3 DATAFILE 'tbs2.dbf' SIZE 1M EXTENT MANAGEMENT LOCAL AUTOALLOCATE;

-- Task 2 
CREATE USER DBMS2_LAB2 IDENTIFIED BY DBMS2_LAB2 DEFAULT TABLESPACE TBS1;
alter user DBMS2_LAB2 quota 1M on TBS1;


-- Task 3
CREATE TABLE DEPARTMENT(
    DEPT_ID NUMBER(2),
    DEPT_NAME VARCHAR2(20) NOT NULL,
    CONSTRAINT DEPT_ID_PK PRIMARY KEY (DEPT_ID)
)TABLESPACE TBS1;

CREATE TABLE STUDENT(
    STUDENT_ID NUMBER(20),
    STUDENT_NAME VARCHAR2(40) NOT NULL,
    DEPT_ID NUMBER(2),
    CONSTRAINT STUDENT_ID_PK PRIMARY KEY (STUDENT_ID),
    CONSTRAINT STUDENT_DEPT_ID_FK FOREIGN KEY (DEPT_ID) REFERENCES DEPARTMENT(DEPT_ID)
)TABLESPACE TBS1;

-- TASK 4
CREATE TABLE COURSE(
    COURSE_CODE NUMBER(10),
    COURSE_NAME VARCHAR2(30) NOT NULL,
    CREDIT NUMBER(2),
    DEPT_ID NUMBER(2),
    CONSTRAINT COURSE_CODE_PK PRIMARY KEY (COURSE_CODE),
    CONSTRAINT COURSE_DEPT_ID_FK FOREIGN KEY (DEPT_ID) REFERENCES DEPARTMENT(DEPT_ID)
)TABLESPACE TBS2;


-- TASK 5
INSERT INTO DEPARTMENT VALUES(1, 'CSE');

INSERT INTO STUDENT VALUES(1, 'STUDENT1', 1);
INSERT INTO STUDENT VALUES(2, 'STUDENT2', 1);
INSERT INTO STUDENT VALUES(3, 'STUDENT3', 1);
INSERT INTO STUDENT VALUES(4, 'STUDENT4', 1);
INSERT INTO STUDENT VALUES(5, 'STUDENT5', 1);

INSERT INTO COURSE VALUES(1, 'COURSE1', 3, 1);
INSERT INTO COURSE VALUES(2, 'COURSE2', 3, 1);
INSERT INTO COURSE VALUES(3, 'COURSE3', 3, 1);
INSERT INTO COURSE VALUES(4, 'COURSE4', 3, 1);
INSERT INTO COURSE VALUES(5, 'COURSE5', 3, 1);


-- TASK 6
SELECT COURSE_NAME, DEPARTMENT.DEPT_NAME
FROM COURSE, DEPARTMENT
WHERE COURSE.DEPT_ID = DEPARTMENT.DEPT_ID;

-- TASK 7
SELECT TABLESPACE_NAME, BYTES/1024/1024 MB
FROM DBA_FREE_SPACE WHERE TABLESPACE_NAME = 'TBS1';

SELECT TABLESPACE_NAME, BYTES/1024/1024 MB
FROM DBA_FREE_SPACE WHERE TABLESPACE_NAME = 'TBS2'

-- TASK 8
ALTER TABLESPACE TBS1 ADD DATAFILE 'tbs1_2.dbf' SIZE 1M;
ALTER TABLESPACE TBS1 ADD DATAFILE 'tbs1_3.dbf' SIZE 1M;

-- TASK 9
ALTER DATABASE DATAFILE 'tbs2.dbf' RESIZE 4M;

-- TASK 10
SELECT TABLESPACE_NAME, BYTES/1024/1024 MB
FROM DBA_DATA_FILES WHERE TABLESPACE_NAME = 'TBS1';

SELECT TABLESPACE_NAME, BYTES/1024/1024 MB
FROM DBA_DATA_FILES WHERE TABLESPACE_NAME = 'TBS2';

-- TASK 11
ALTER TABLESPACE TBS1 OFFLINE;
SELECT * FROM STUDENT;

-- TASK 12
DROP TABLESPACE TBS1 INCLUDING CONTENTS AND DATAFILES CASCADE CONSTRAINTS;

-- TASK 13
DROP TABLESPACE TBS2 INCLUDING CONTENTS;
