create table Faculties(
faculty_id INT primary key,
faculty_name VARCHAR(100),
faculty_address VARCHAR(300),
faculty_date_of_construction DATE,
faculty_specialization_name VARCHAR(100),
)

create table Departments(
department_id INT primary key,
department_name VARCHAR(50),
department_description VARCHAR(500),
department_motto VARCHAR(100) unique,
)

create table Volunteers(
volunteer_id INT primary key,
volunteer_name VARCHAR(50),
volunteer_cnp CHAR(13),
volunteer_Faculty_id INT foreign key references Faculties(faculty_id),
volunteer_BirthDate DATE,
volunteer_EnrolmentDate DATE,
volunteer_BC BIT,
volunteer_is_presindent_of_OSUBB BIT,
volunteer_department_id INT foreign key references Departments(department_id),
)

create table Recruting(
recruting_Motto_of_year VARCHAR(200) unique,
recruting_volunteer_id INT foreign key references Volunteers(volunteer_id),
recruting_starting_date DATE unique,
recruting_ending_date DATE unique,
primary key (recruting_starting_date, recruting_ending_date)
)

alter table Volunteers
add start_period_of_recrutation DATE foreign key references Recruting(recruting_starting_date)

alter table Volunteers
add end_period_of_recrutation DATE foreign key references Recruting(recruting_ending_date)

create table BC(
BC_start_of_campaign DATE unique,
BC_end_of_campaign DATE unique,
primary key (BC_start_of_campaign, BC_end_of_campaign),
)

create table DepartmentsOfficials(
department_id INT foreign key references Departments(department_id),
volunteer_id INT foreign key references Volunteers(volunteer_id),
BC_start_of_campaign DATE foreign key references BC(BC_start_of_campaign),
BC_end_of_campaign DATE foreign key references BC(BC_end_of_campaign),
)

create table Sponsors(
sponsor_id INT primary key,
sponsor_name VARCHAR(50),
sponsor_registration_number INT,
sponsor_CUI VARCHAR(20),
type_of_sponsorization VARCHAR(50),
)

create table Projects(
project_id INT primary key,
project_name VARCHAR(100),
project_start_of_implementation DATE unique,
project_end_of_implementation DATE unique,
project_description VARCHAR(100),
project_responsible INT foreign key references Volunteers(volunteer_id),
project_location VARCHAR(100),
)

create table Sponsor_Project(
project_id INT foreign key references Projects(project_id),
sponsor_id INT foreign key references Sponsors(sponsor_id),
start_of_collaboration DATE,
end_of_colaboration DATE,
list_of_materials_provided VARCHAR(500),
)

create table Participate(
volunteer_id INT foreign key references Volunteers(volunteer_id),
project_id INT foreign key references Projects(project_id),
)

create table CasutaGalbena(
CasutaGalbena_location VARCHAR(100) primary key,
CasutaGalbena_size INT,
CasutaGalbena_is_open BIT,
CasutaGalbena_has_party_tonight BIT,
CasutaGalbena_cleaning_shift_responsible INT foreign key references Volunteers(volunteer_id),
)

create table Party_Casootz(
party_location VARCHAR(100) foreign key references CasutaGalbena(CasutaGalbena_location),
volunteer_coming INT foreign key references Volunteers(volunteer_id),
materials_nedeed VARCHAR(500),
is_music_on BIT,
games_to_play VARCHAR(500),
)
