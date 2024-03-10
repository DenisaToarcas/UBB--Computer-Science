create table Cities(
	cityID int primary key,
	cityName varchar (200) unique
)

create table Stadiums(
	stadiumID int primary key,
	stadiumName varchar(200),
	belongingCity int foreign key references Cities(cityID)
)

create table NationalTeams(
	teamID int primary key,
	belongingCountry varchar(100) unique
)

create table Players(
	playerID int primary key,
	playerName varchar(200),
	playerBirthDate date,
	playerNationality varchar(100),
	playerPosition varchar(100),
	ifCaptain BIT,
	teamID int foreign key references NationalTeams(teamID)
)

create table Coaches(
	coachID int primary key,
	coachName varchar(200),
	coachNationality varchar(100),
	teamID int foreign key references NationalTeams(teamID)
)

create table Games(
	gameDate date,
	team1ID int foreign key references NationalTeams(teamID),
	team2ID int foreign key references NationalTeams(teamID),
	--constraint PK_Games primary key (gameDate, team1ID, team2ID),
	stadiumID int foreign key references Stadiums(stadiumID),
	finalScore int,
	winnerTeam int,
	finalScoreOvertime BIT
)

go
create or alter procedure uspAddGame
	@gameDate date,
	@team1ID int,
	@team2ID int,
	@stadiumID int,
	@finalScore int,
	@winnerTeam int,
	@finalScoreOvertime BIT
as
	begin
		if exists (
		select 1
		from Games
		where gameDate = @gameDate and
		((team1ID = @team1ID and team2ID = @team2ID) or
		 (team1ID = @team2ID and team2ID = @team1ID)
		)
		)
			begin
				update Games
				set finalScore = @finalScore
				where gameDate = @gameDate and
			((team1ID = @team1ID and team2ID = @team2ID) or
			 (team1ID = @team2ID and team2ID = @team1ID)
			)
			end
		else
			begin
				insert into Games(gameDate, team1ID, team2ID, stadiumID, finalScore, winnerTeam, finalScoreOvertime)
				values (@gameDate, @team1ID, @team2ID, @stadiumID, @finalScore, @finalScoreOvertime)
			end
	end
go

create or alter view viewStadiums
as
	select stadiumName
	from Stadiums
	inner join Games
	on Games.stadiumID = Stadiums.stadiumID and Games.finalScoreOvertime = 1
go

create or alter function ufNoOfTeams(@stadiumID int, @scoreDifference int)
returns int
as
begin
	declare @noOfTeams int
	set @noOfTeams = 0

	select @noOfTeams = count(distinct winnerTeam)
	from Games
	where stadiumID = @stadiumID 
	and abs(finalScore) > @scoreDifference
	and winnerTeam not in (
	select team1ID
	from Games
	where stadiumID = @stadiumID
	and winnerTeam != team1ID
	)
	and winnerTeam not in (
	select team2ID
	from Games
	where stadiumID = @stadiumID
	and winnerTeam != team2ID
	)

	return @noOfTeams
end