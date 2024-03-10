--insert data for at least 4 tables
insert into Faculties(faculty_id, faculty_name, faculty_address, faculty_date_of_construction, faculty_specialization_name) values (1, 'UBB FMI',  'Central Building', '1950-10-17', 'mate-info')
--statement that violates referential integrity constratints
insert into Faculties(faculty_id, faculty_name, faculty_address, faculty_date_of_construction, faculty_specialization_name) values (1, 'UBB FMI',  'Central Building, Kogalniceanu, no. 1', '1950-10-17', 'info')
insert into Faculties(faculty_id, faculty_name, faculty_address, faculty_date_of_construction, faculty_specialization_name) values (2, 'UBB FMI',  'Central Building, Kogalniceanu, no. 1', '1950-10-17', 'info')
insert into Faculties(faculty_id, faculty_name, faculty_address, faculty_date_of_construction, faculty_specialization_name) values (3, 'UBB FMI',  'Central Building, Kogalniceanu, no. 1', '1950-10-17', 'mate')
insert into Faculties(faculty_id, faculty_name, faculty_address, faculty_date_of_construction, faculty_specialization_name) values (4, 'UBB FSEGA',  'street Teodor Mihali, no. 58-60', '1990-05-12', 'info-eco')
insert into Faculties(faculty_id, faculty_name, faculty_address, faculty_date_of_construction, faculty_specialization_name) values (5, 'UBB FSEGA',  'street Teodor Mihali, no. 58-60', '1990-05-12', 'management')
insert into Faculties(faculty_id, faculty_name, faculty_address, faculty_date_of_construction, faculty_specialization_name) values (6, 'UBB FSEGA',  'street Teodor Mihali, no. 58-60', '1990-05-12', 'contability')
insert into Faculties(faculty_id, faculty_name, faculty_address, faculty_date_of_construction, faculty_specialization_name) values (7, 'UBB FSEGA',  'street Teodor Mihali, no. 58-60', '1990-05-12', 'economics')
insert into Faculties(faculty_id, faculty_name, faculty_address, faculty_date_of_construction, faculty_specialization_name) values (8, 'UBB TTF',  'street Kogalniceanu, no. 20', '1943-04-28', 'direction')
insert into Faculties(faculty_id, faculty_name, faculty_address, faculty_date_of_construction, faculty_specialization_name) values (9, 'UBB TTF',  'street Kogalniceanu, no. 20', '1943-04-28', 'movie district')
insert into Faculties(faculty_id, faculty_name, faculty_address, faculty_date_of_construction, faculty_specialization_name) values (10, 'UBB TTF',  'street Kogalniceanu, no. 20', '1943-04-28', 'acting')

insert into Departments(department_id, department_name, department_description, department_motto) values(1, 'Tineret', 'people on Tineret create projects for the youngsters from Cluj', 'Sharing is caring')
insert into Departments(department_id, department_name, department_description, department_motto) values(2, 'HR', 'people on HR create projects for OSUBB volunteers', 'Noi o avem mai mare si conteaza')
insert into Departments(department_id, department_name, department_description, department_motto) values(3, 'Img&PR', 'foto-video stuff and online promoting', 'VIbe check!')
insert into Departments(department_id, department_name, department_description, department_motto) values(4, 'FR', 'getting sponsorships and buget for projects', 'Money calling')
insert into Departments(department_id, department_name, department_description, department_motto) values(5, 'Scriere de proiecte', 'getting the details ready for all projects', 'Whop whop, projects ready!')
insert into Departments(department_id, department_name, department_description, department_motto) values(6, 'Evenimente', 'parties', 'PARTY')
insert into Departments(department_id, department_name, department_description, department_motto) values(7, 'Relatii externe', 'maintaining the external relationships with ONGs', 'EXTERNEEEEE!')

insert into Volunteers(volunteer_id, volunteer_name, volunteer_cnp, volunteer_Faculty_id, volunteer_BirthDate, volunteer_EnrolmentDate, volunteer_BC, volunteer_is_presindent_of_OSUBB, volunteer_department_id) values(1, 'Ioana Franghiu', '1111111111111', 1, '2000-10-19', '2016-02-19', 1, 1, 2)
insert into Volunteers(volunteer_id, volunteer_name, volunteer_cnp, volunteer_Faculty_id, volunteer_BirthDate, volunteer_EnrolmentDate, volunteer_BC, volunteer_is_presindent_of_OSUBB, volunteer_department_id) values(2, 'Deni Toarcas', '2222222222222', 2, '2003-04-16', '2021-09-21', 0, 0, 1)
insert into Volunteers(volunteer_id, volunteer_name, volunteer_cnp, volunteer_Faculty_id, volunteer_BirthDate, volunteer_EnrolmentDate, volunteer_BC, volunteer_is_presindent_of_OSUBB, volunteer_department_id) values(3, 'Luci', '3333333333333', 3, '2000-02-21', '2016-02-19', 1, 0, 4)
insert into Volunteers(volunteer_id, volunteer_name, volunteer_cnp, volunteer_Faculty_id, volunteer_BirthDate, volunteer_EnrolmentDate, volunteer_BC, volunteer_is_presindent_of_OSUBB, volunteer_department_id) values(4, 'Mihai', '4444444444444', 4, '2000-02-21', '2017-07-01', 0, 0, 3)
insert into Volunteers(volunteer_id, volunteer_name, volunteer_cnp, volunteer_Faculty_id, volunteer_BirthDate, volunteer_EnrolmentDate, volunteer_BC, volunteer_is_presindent_of_OSUBB, volunteer_department_id) values(5, 'Tudor', '5555555555555', 1, '2000-10-19', '2016-02-19', 1, 1, 2)
insert into Volunteers(volunteer_id, volunteer_name, volunteer_cnp, volunteer_Faculty_id, volunteer_BirthDate, volunteer_EnrolmentDate, volunteer_BC, volunteer_is_presindent_of_OSUBB, volunteer_department_id) values(6, 'Sinziana', '6666666666666', 1, '2000-10-19', '2016-02-19', 0, 0, 2)
insert into Volunteers(volunteer_id, volunteer_name, volunteer_cnp, volunteer_Faculty_id, volunteer_BirthDate, volunteer_EnrolmentDate, volunteer_BC, volunteer_is_presindent_of_OSUBB, volunteer_department_id) values(7, 'Munceanu', '7777777777777', 2, '2002-11-23', '2016-02-19', 0, 0, 1)

insert into Projects(project_id, project_name, project_start_of_implementation, project_end_of_implementation, project_description, project_responsible, project_location) values(1, 'Future Up', '2024-02-16', '2024-02-26', 'project for finding an intership', 7, 'Central Building')
insert into Projects(project_id, project_name, project_start_of_implementation, project_end_of_implementation, project_description, project_responsible, project_location) values(2, 'JSU', '2024-07-02', '2024-07-20', 'summer camp for 11 graders', 2, 'Hasdeu')
insert into Projects(project_id, project_name, project_start_of_implementation, project_end_of_implementation, project_description, project_responsible, project_location) values(3, 'Saptamana Bobocului', '2023-10-04', '2023-10-17', 'integrating the boboci in the students comunity',3, 'Catina Hasdeu')
insert into Projects(project_id, project_name, project_start_of_implementation, project_end_of_implementation, project_description, project_responsible, project_location) values(4, 'Trix', '2023-12-08', '2023-12-23', 'leave out the stress before sesiune', 6, 'Central Building')
insert into Projects(project_id, project_name, project_start_of_implementation, project_end_of_implementation, project_description, project_responsible, project_location) values(5, 'UBB Fest', '2024-05-10', '2024-05-28', 'biggest project by OSUBB', null, 'Central Park of Cluj')
insert into Projects(project_id, project_name, project_start_of_implementation, project_end_of_implementation, project_description, project_responsible, project_location) values(6, 'PitchLab', '2023-11-12', '2023-11-20', 'advertising fans would love this', null, 'CCS')

insert into Volunteers(volunteer_id, volunteer_name, volunteer_cnp, volunteer_Faculty_id, volunteer_BirthDate, volunteer_EnrolmentDate, volunteer_BC, volunteer_is_presindent_of_OSUBB, volunteer_department_id) values(8, 'Geo', '1111111111111',8, '2001-03-19', '2016-02-19', 1, 0, 2)
insert into Volunteers(volunteer_id, volunteer_name, volunteer_cnp, volunteer_Faculty_id, volunteer_BirthDate, volunteer_EnrolmentDate, volunteer_BC, volunteer_is_presindent_of_OSUBB, volunteer_department_id) values(9, 'Julieta', '1111111111111', 8, '2001-03-09', '2016-02-19', 1, 0, 2)
insert into Volunteers(volunteer_id, volunteer_name, volunteer_cnp, volunteer_Faculty_id, volunteer_BirthDate, volunteer_EnrolmentDate, volunteer_BC, volunteer_is_presindent_of_OSUBB, volunteer_department_id) values(10, 'Iulia', '1111111111111', 9, '2002-11-19', '2016-02-19', 1, 0, 2)
insert into Volunteers(volunteer_id, volunteer_name, volunteer_cnp, volunteer_Faculty_id, volunteer_BirthDate, volunteer_EnrolmentDate, volunteer_BC, volunteer_is_presindent_of_OSUBB, volunteer_department_id) values(11, 'Toni', '1111111111111', 10, '2002-11-19', '2016-02-19', 1, 0, 2)

insert into Sponsors(sponsor_id, sponsor_name, sponsor_registration_number, sponsor_CUI, type_of_sponsorization) values(1, 'BigBelly', 123, '123456', '50 pizzas and 20 portions of food')
insert into Sponsors(sponsor_id, sponsor_name, sponsor_registration_number, sponsor_CUI, type_of_sponsorization) values(2, 'Pizza Acrobatica', 124, '1234567', '50 pizzas')
insert into Sponsors(sponsor_id, sponsor_name, sponsor_registration_number, sponsor_CUI, type_of_sponsorization) values(3, 'Greco', 125, '1234568', '75 Gyros')
insert into Sponsors(sponsor_id, sponsor_name, sponsor_registration_number, sponsor_CUI, type_of_sponsorization) values(4, 'Sushi Master', 126, '1234569', '15 sushi plates')
insert into Sponsors(sponsor_id, sponsor_name, sponsor_registration_number, sponsor_CUI, type_of_sponsorization) values(5, 'Arobs', 127, '1234560', '15 goody bags')
insert into Sponsors(sponsor_id, sponsor_name, sponsor_registration_number, sponsor_CUI, type_of_sponsorization) values(6, 'Emerson', 128, '12345601', '15 goody bags')
insert into Sponsors(sponsor_id, sponsor_name, sponsor_registration_number, sponsor_CUI, type_of_sponsorization) values(7, 'Squad Store', 129, '12345602', 'vouchers')

insert into Sponsor_Project(project_id, sponsor_id, start_of_collaboration, end_of_colaboration, list_of_materials_provided) values(1, 1, '2023-02-16', '2023-02-26', 'pizza')
insert into Sponsor_Project(project_id, sponsor_id, start_of_collaboration, end_of_colaboration, list_of_materials_provided) values(2, 1, '2024-07-02', '2024-07-02', 'pizza')
insert into Sponsor_Project(project_id, sponsor_id, start_of_collaboration, end_of_colaboration, list_of_materials_provided) values(3, 2, '2023-10-04', '2023-10-17', 'gyros')
insert into Sponsor_Project(project_id, sponsor_id, start_of_collaboration, end_of_colaboration, list_of_materials_provided) values(4, 4, '2023-12-08', '2023-12-23', 'sushi')
insert into Sponsor_Project(project_id, sponsor_id, start_of_collaboration, end_of_colaboration, list_of_materials_provided) values(6, 5, '2023-11-12', '2023-11-20', 'goody bags')

insert into Participate(volunteer_id, project_id) values(7, 1)
insert into Participate(volunteer_id, project_id) values(2, 2)
insert into Participate(volunteer_id, project_id) values(3, 3)
insert into Participate(volunteer_id, project_id) values(6, 4)
insert into Participate(volunteer_id, project_id) values(11,1)
insert into Participate(volunteer_id, project_id) values(10,1)
insert into Participate(volunteer_id, project_id) values(10,2)
insert into Participate(volunteer_id, project_id) values(9,2)
insert into Participate(volunteer_id, project_id) values(8, 3)
insert into Participate(volunteer_id, project_id) values(7, 3)
insert into Participate(volunteer_id, project_id) values(6, 2)
insert into Participate(volunteer_id, project_id) values(3, 1)

select *
from Faculties

select *
from Departments

select*
from Volunteers

select *
from Projects

select *
from Sponsors

select *
from Sponsor_Project

select *
from Participate

update Volunteers
set volunteer_department_id = 3
where volunteer_id = 8

update Volunteers
set volunteer_department_id = 4
where volunteer_id = 10

--update data for at least 3 tables
update Projects
set project_location = 'Cantina Hasdeu'
where project_responsible = 6

update Volunteers
set volunteer_BC = 1
where volunteer_Faculty_id = 1

update Faculties
set faculty_address = 'street Mihail Kogalniceanu, no. 1'
where faculty_name LIKE 'UBB FMI'

update Faculties
set faculty_date_of_construction = '1954-09-18'
where faculty_name LIKE 'UBB TTF' and faculty_specialization_name = 'acting'

--delete data for at least 2 tabels
delete from Volunteers
where volunteer_is_presindent_of_OSUBB = 1

insert into Volunteers(volunteer_id, volunteer_name, volunteer_cnp, volunteer_Faculty_id, volunteer_BirthDate, volunteer_EnrolmentDate, volunteer_BC, volunteer_is_presindent_of_OSUBB, volunteer_department_id) values(1, 'Ioana Franghiu', '1111111111111', 1, '2000-10-19', '2016-02-19', 1, 1, 2)

delete from Projects
where project_responsible = 3

insert into Projects(project_id, project_name, project_start_of_implementation, project_end_of_implementation, project_description, project_responsible, project_location) values(3, 'Saptamana Bobocului', '2023-10-04', '2023-10-17', 'integrating the boboci in the students comunity',3, 'Catina Hasdeu')

--a. 2 queries with the union operation; use UNION [ALL] and OR;

--first try, but not so good
--select Volunteers.volunteer_name AS 'Volunteers and Projects for 2023/2024'
--from Volunteers
--union
--select Projects.project_name
--from Projects

--selecting the ids of the volunteers that are in BC or are responsible for a Project this year
select Volunteers.volunteer_id AS 'BC and PMs'
from Volunteers
where volunteer_BC = 1
UNION
select Projects.project_responsible
from Projects

--find the ids of the volunteers from HR and BC => people responsible for Teambuilding
select Volunteers.volunteer_id
from Volunteers
where volunteer_department_id = 2 or volunteer_BC = 1 or volunteer_is_presindent_of_OSUBB = 1

--b. 2 queries with the intersection operation; use INTERSECT and IN;

--volunteers from mate-info, info or mate that are PMs
select Volunteers.volunteer_id
from Volunteers
where volunteer_Faculty_id = 1 or volunteer_Faculty_id = 2 or volunteer_Faculty_id = 3
intersect
select Projects.project_responsible
from Projects

--select the department ids for the students from direction, movie district and acting
select Departments.department_id
from Departments
where department_id IN
(
	select Volunteers.volunteer_department_id
	from Volunteers
	where Volunteers.volunteer_Faculty_id = 8 or Volunteers.volunteer_Faculty_id = 9 or Volunteers.volunteer_Faculty_id = 10
)

--c. 2 queries with the difference operation; use EXCEPT and NOT IN;

--select the volunteers that are PMs, but not in BC
select Projects.project_responsible AS 'Ids of PMs that are not part of BC'
from Projects
where project_responsible is NOT NULL
except
select Volunteers.volunteer_id
from Volunteers
where volunteer_BC = 1

--select the faculties of which students have no representative in OSUBB
select distinct Faculties.faculty_name, Faculties.faculty_specialization_name AS 'No volunteers from'
from Faculties
where faculty_id not in(
select Volunteers.volunteer_Faculty_id
from Volunteers
)

--d. 4 queries with INNER JOIN, LEFT JOIN, RIGHT JOIN, and FULL JOIN (one query per operator); one query will join at least 3 tables, while another one will join at least two many-to-many relationships;

--(1) count all volunteers that are responsible for a project
select count(*) as 'No of volunteers that are PMs'
from Volunteers inner join Projects on Volunteers.volunteer_id = Projects.project_responsible

--selecting all the projects with the sponsors/project (even if the project does not have a Sponsor assigned yet)
--select *
--from Projects left join Sponsor_Project on Projects.project_id = Sponsor_Project.project_id

--(2) - selecting all info about volunteers that are PMs, their projects and sponsors (3 tables)
select *
from Volunteers left join Projects on Volunteers.volunteer_id = Projects.project_responsible
inner join Sponsor_Project on Projects.project_id = Sponsor_Project.project_id

--EXPLANATION
--selecting all volunteers and see if they are PMs (project_id not null)
select *
from Volunteers left join Projects on Volunteers.volunteer_id = Projects.project_responsible
--we then used INNER JOIN for selecting only the PMs with their projects and sponsors

--(3) the materials that volunteers will obtain by participating in a project
--first, we select the volunteers and the projects in which they participate
--then we inner join the result with the sponsor_project table to find the materials provided at each project
--2 many-to-many
select *
from Volunteers right join Participate on Volunteers.volunteer_id = Participate.volunteer_id
inner join Sponsor_Project on Sponsor_Project.project_id = Participate.project_id

--(4) select all projects and volunteers that participate (even if there are projects in which no volunteer is signed up yet)
select *
from Projects full outer join Participate on Projects.project_id = Participate.project_id
full outer join Volunteers on Volunteers.volunteer_id = Participate.volunteer_id

--e. 2 queries with the IN operator and a subquery in the WHERE clause; in at least one case, the subquery must include a subquery in its own WHERE clause;

--Enrolment date of the most experienced volunteer in project Future Up
select MIN(volunteer_EnrolmentDate) as "Enrolment date of the most experienced volunteer in project Future Up"
from Volunteers
where Volunteers.volunteer_id in(
select volunteer_id
from Participate
where Participate.project_id = 1
)

--select the sponsors info of the sponsors from projects with no PMs (no responsible)
select *
from Sponsors
where Sponsors.sponsor_id in
(
select sponsor_id
from Sponsor_Project
where Sponsor_Project.project_id not in
(
select project_id
from Projects
where Projects.project_responsible is not null
)
)

--f. 2 queries with the EXISTS operator and a subquery in the WHERE clause;

--select the names of the sponsors which haven't been assigned to a project yet (in alfabetical order)
select *
from Sponsors
where not exists
(
select *
from Sponsor_Project
where Sponsor_Project.sponsor_id = Sponsors.sponsor_id
)
order by sponsor_name

--select the volunteers that have not signed up in a project yet, and order them by experience in OSUBB
select *
from Volunteers
where not exists
(
select *
from Participate
where Participate.volunteer_id = Volunteers.volunteer_id
)
order by Volunteers.volunteer_EnrolmentDate

--g. 2 queries with a subquery in the FROM clause;

--select the volunteers that are part of BC and they enroled in 2016
select count(*) AS 'BC volunteers from 2016'
from (
select *
from Volunteers
where Volunteers.volunteer_BC = 1
) BC
where YEAR(BC.volunteer_EnrolmentDate) = 2016


--select the top 3 sponsors that are assigned to a project in 2023
select *
from
(
select top 3 *
from Sponsors
where Sponsors.sponsor_id in
(
select sponsor_id
from Sponsor_Project
where Sponsor_Project.project_id in
(
select project_id
from Projects
where YEAR(Projects.project_start_of_implementation) = 2023
)
)
) Top3Sponsors

--h. 4 queries with the GROUP BY clause, 3 of which also contain the HAVING clause; 2 of the latter will also have a subquery in the HAVING clause; use the aggregation operators: COUNT, SUM, AVG, MIN, MAX;

--select the projects ids and names of the projects held in Hasdeu
select Projects.project_id, Projects.project_name, Projects.project_location
from Projects inner join(
select project_location
from Projects
group by project_location
) L on Projects.project_location = L.project_location and Projects.project_location LIKE '%Hasdeu'

--select the volunteers names for the volunteers that enroled in OSUBB after 2016
select Volunteers.volunteer_name
from Volunteers inner join
(
select volunteer_EnrolmentDate
from Volunteers
Group by Volunteers.volunteer_EnrolmentDate
having Year(volunteer_EnrolmentDate) >= 2016
) E on Volunteers.volunteer_EnrolmentDate = E.volunteer_EnrolmentDate

--select and group the volunteers by the department from which they participate in projects(alfabetical order)
select Volunteers.volunteer_department_id, Volunteers.volunteer_name
from Volunteers
Group by Volunteers.volunteer_name, Volunteers.volunteer_department_id
having Volunteers.volunteer_department_id in
(
select distinct Volunteers.volunteer_department_id
from Volunteers, Participate
where Volunteers.volunteer_id = Participate.volunteer_id
)

--count the number of projects that do have assigned a sponsor until now
select count(*) AS 'Projects with sponsors', MIN(Projects.project_start_of_implementation) AS 'The first starting date', MAX(Projects.project_start_of_implementation) AS 'The last starting date'
from Projects inner join
(
select Projects.project_id, Projects.project_start_of_implementation
from Projects
Group by Projects.project_id, Projects.project_start_of_implementation
having Projects.project_id in
(
select Sponsor_Project.project_id
from Sponsor_Project
where Sponsor_Project.sponsor_id is not null
)
) ProjectsWithSponsors on Projects.project_id = ProjectsWithSponsors.project_id

--i. 4 queries using ANY and ALL to introduce a subquery in the WHERE clause (2 queries per operator); rewrite 2 of them with aggregation operators, and the other 2 with IN / [NOT] IN.

--Querries with ALL
--select the projects with no participants
select distinct project_name
from Projects
where Projects.project_id <> all
(
select project_id
from Participate
)

--the rewriting of this query with not in
select distinct project_name
from Projects
where Projects.project_id not in
(
select project_id
from Participate
)

--select the departments with no volunteers
select top 2 department_name
from Departments
where Departments.department_id <> all
(
select volunteer_department_id
from Volunteers
)

--the rewriting of this query with not in
select top 2 department_name
from Departments
where Departments.department_id not in
(
select volunteer_department_id
from Volunteers
)

--Querries with ANY
--find the first project to start this year and select the rest of them
select project_id, project_name, project_start_of_implementation
from Projects
where Projects.project_start_of_implementation > any
(
select project_start_of_implementation
from Projects
)

--the rewriting of this query with aggregation operators
select project_id, project_name, project_start_of_implementation
from Projects
where project_start_of_implementation in(
select project_start_of_implementation
from Projects
group by project_start_of_implementation
having project_start_of_implementation >
(
select MIN(project_start_of_implementation)
from Projects
)
)

--select the project that ends last
select project_id, project_name, project_end_of_implementation
from Projects
where Projects.project_end_of_implementation = any
(
select MAX(project_end_of_implementation)
from Projects
)

--rewriting of this query with aggregation operators
select project_id, project_name, project_end_of_implementation
from Projects
where project_end_of_implementation in(
select project_end_of_implementation
from Projects
group by project_end_of_implementation
having project_end_of_implementation =
(
select MAX(project_end_of_implementation)
from Projects
)
)