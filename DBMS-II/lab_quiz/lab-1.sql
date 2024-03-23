-- task 1
select name from instructor where dept_name = 'Biology';

-- task 2
select title from course where course_id in
(
    select course_id from 
    student left join takes on 
    student.ID = takes.ID 
    where student.ID = '12345'
);

-- task 3
select name, dept_name as dept from student where id in(
    select distinct id from takes where course_id in(
        select course_id from course
        where dept_name = 'Comp. Sci.'
    )
);

-- task 4
select name from student where id in(
    select id from takes
    where course_id = 'CS-101' and semester = 'Spring' and year = 2018
);


-- task 5
select name from student where id in (
    select id from(
        select count(course_id) as ct, id from takes where course_id in(
            SELECT course_id from course where course_id like 'CS%'
        )
        group by id 
        order by ct desc
    ) where rownum = 1
);


-- task 6





