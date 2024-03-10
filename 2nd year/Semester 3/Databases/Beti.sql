create table Patient(
	patientID int primary key,
	patientName varchar(200),
	patientBirthDate date,
	patientGender varchar(1)
)

create table Doctor(
	doctorID int primary key,
	doctorName varchar(200),
	doctorDepartment varchar(100)
)

create table Medication(
	medicationID int primary key,
	medicationName varchar(200) unique,
	medicationManufacturer varchar(200)
)

create table Appointment(
	appointmentID int primary key,
	patientID int foreign key references Patient(patientID),
	doctorID int foreign key references Doctor(doctorID),
	dateAndTime datetime2,
)

create table Prescription(
	prescriptionID int primary key,
	medicationID int foreign key references Medication(medicationID),
	appointmentID int foreign key references Appointment(appointmentID),
	dosage int
)

go
create or alter procedure uspAddAppointment
	@patientID int,
	@doctorID int,
	@dateTime datetime2
as
	begin
		if exists(
		select 1
		from Appointment
		where patientID = @patientID and @doctorID = doctorID
		)
			begin
				update Appointment
				set dateAndTime = @dateTime
				where patientID = @patientID and doctorID = @doctorID
			end
		else
			begin
				declare @appointmentID int
				set @appointmentID = (select count(*)
				from Appointment
				)
				set @appointmentID = @appointmentID + 1

				insert into Appointment(appointmentID, patientID, doctorID, dateAndTime)
				values (@appointmentID, @patientID, @doctorID, @dateTime)
			end
	end
go

create or alter view viewAppointmentsInFebruary
as
	select doctorName
	from Doctor
	inner join Appointment
	on Appointment.doctorID = Doctor.doctorID
	and MONTH(Appointment.dateAndTime) = 2
	and YEAR(Appointment.dateAndTime) = 2024
go

create or alter function ufCountMedications(@doctorID int)
returns table
as
	return
		select medicationName, count(*) as TotalCount
		from Medication
		inner join Prescription on
		Prescription.medicationID = Medication.medicationID
		inner join Appointment on
		Appointment.appointmentID = Prescription.appointmentID
		group by medicationName
go

-- Insert data into Patient table
INSERT INTO Patient (patientID, patientName, patientBirthDate, patientGender)
VALUES
    (1, 'John Doe', '1990-05-15', 'M'),
    (2, 'Jane Smith', '1985-08-22', 'F')
    -- Add more patients as needed

-- Insert data into Doctor table
INSERT INTO Doctor (doctorID, doctorName, doctorDepartment)
VALUES
    (1, 'Dr. Smith', 'Cardiology'),
    (2, 'Dr. Johnson', 'Orthopedics')
    -- Add more doctors as needed

-- Insert data into Medication table
INSERT INTO Medication (medicationID, medicationName, medicationManufacturer)
VALUES
    (1, 'Aspirin', 'PharmaCo'),
    (2, 'Ibuprofen', 'MediCare')
    -- Add more medications as needed

-- Insert data into Appointment table
EXEC uspAddAppointment @patientID = 1, @doctorID = 1, @dateTime = '2024-02-01T10:00:00'
EXEC uspAddAppointment @patientID = 2, @doctorID = 2, @dateTime = '2024-02-05T14:30:00'
-- Add more appointments as needed

-- Insert data into Prescription table
INSERT INTO Prescription (prescriptionID, medicationID, appointmentID, dosage)
VALUES
    (1, 1, 1, 2),
    (2, 2, 2, 1)
    -- Add more prescriptions as needed

-- Execute the function for a specific doctor ID (e.g., DoctorID = 1)
SELECT *
FROM ufCountMedications(1);
