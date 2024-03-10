create table Accounts(
	accountID int primary key,
	username varchar(200),
	emailAddress varchar(200),
	ifVerified BIT
)

create table Followers(
	accFollowedID int foreign key references Accounts(accountID),
	followerID int foreign key references Accounts(accountID)
)

create table Pictures(
	pictureID int primary key,
	uploadDate datetime,
	size int
)

create table Posts(
	postID int primary key,
	accountID int foreign key references Accounts(accountID),
	postDescription varchar(200)
)

create table PostsPictures(
	postID int foreign key references Posts(postID),
	pictureID int foreign key references Pictures(pictureID)
)

create table Activities(
	accountID int foreign key references Accounts(accountID),
	postID int foreign key references Posts(postID),
	activityType varchar(10),
	ifComment varchar(100),
	activityDate datetime
)

go
create or alter procedure uspAddActivity
	@accountID int,
	@postID int,
	@activityType varchar(10),
	@ifComment varchar(100),
	@activityDate datetime
as
	begin
		if exists(
		select 1
		from Activities
		where Activities.postID = @postID and Activities.accountID = @accountID
		)
			begin
				update Activities
				set activityDate = @activityDate
				where accountID = @accountID and postID = @postID
			end
		else
			begin
				insert into Activities(accountID, postID, activityType, ifComment, activityDate) values
				(@accountID, @postID, @activityType, @ifComment, @activityDate)
			end
	end
go

create or alter view viewPosts
as
	select Activities.accountID as UserAcc, COUNT(*) as NumberOfPosts
	from Activities
	inner join Accounts
	on Activities.accountID = Accounts.accountID
	and 10 <= (
	select COUNT(*)
	from Activities
	where Activities.accountID = Accounts.accountID
	and Activities.activityType LIKE 'comment'
	)
	group by Activities.accountID
go

create or alter function ufListNoOfAcc (@R int)
returns int
as
begin
	declare @NoOfAccounts int
	
	set @NoOfAccounts = 0
	select @NoOfAccounts = COUNT(*)
	from Accounts
	inner join Followers
	on Accounts.accountID = Followers.accFollowedID
	and @R <= (
	select COUNT(*)
	from Followers
	where Followers.accFollowedID = Accounts.accountID
	)
	
	return @NoOfAccounts
end
go

insert into Accounts(accountID, username, emailAddress, ifVerified) values (1, '1', '1', 1), (2, '2', '2', 0)
insert into Followers(accFollowedID, followerID) values(1, 2)
insert into Followers(accFollowedID, followerID) values(2, 1)