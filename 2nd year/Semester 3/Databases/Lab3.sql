--LAB 3 QUERY
--Write SQL scripts that:
--a. modify the type of a column;
--b. add / remove a column;
--c. add / remove a DEFAULT constraint;
--d. add / remove a primary key;
--e. add / remove a candidate key;
--f. add / remove a foreign key;
--g. create / drop a table.


--a. modify the type of a column;
go
create or alter procedure uspModifyColumnType
	@TableName nvarchar(100),
	@ColumnName nvarchar(100),
	@NewType nvarchar(20)
	--@output nvarchar(20) OUTPUT
as
	begin
		declare @ModifyColumnType nvarchar(max)

		--we get the value of the column before modifying it to be able to have the reverse action
		--SELECT @output = DATA_TYPE
		--FROM INFORMATION_SCHEMA.COLUMNS
		--WHERE TABLE_NAME = @TableName AND COLUMN_NAME = @ColumnName

		set @ModifyColumnType = 'alter table ' + QUOTENAME(@TableName) + ' alter column ' + 
		QUOTENAME(@ColumnName) + ' ' + QUOTENAME(@NewType)

		exec sp_executesql @ModifyColumnType

		declare @NotNull nvarchar(max)
		set @NotNull = 'alter table ' + QUOTENAME(@TableName) + ' alter column ' + 
		QUOTENAME(@ColumnName) + QUOTENAME(@NewType) +' not null'

		exec sp_executesql @NotNull
	end
go

--declare @output nvarchar(100)
--set @output = ''

exec uspModifyColumnType
	@TableName = 'Table',
	@ColumnName = 'Column',
	@NewType = 'bigint'
	--@output = @output OUTPUT

	--PRINT(@output)
go

--b. add / remove a column;
--ADD COLUMN
create or alter procedure uspAddColumn
	@TableName nvarchar(100),
	@NewColumn nvarchar(100),
	@NewType nvarchar(20)
as
	begin
		declare @AddColumn nvarchar(max)
		set @AddColumn = 'alter table ' + QUOTENAME(@TableName) + ' add ' + 
		QUOTENAME(@NewColumn) + ' ' + QUOTENAME(@NewType)

		exec sp_executesql @AddColumn

		declare @NotNull nvarchar(max)
		set @NotNull = 'alter table ' + QUOTENAME(@TableName) + ' alter column ' + 
		QUOTENAME(@NewColumn) + QUOTENAME(@NewType) +' not null'

		exec sp_executesql @NotNull
	end
go

exec uspAddColumn
	@TableName = 'Table',
	@NewColumn = 'Column2',
	@NewType = 'smallint'
go

--DELETE COLUMN
create or alter procedure uspRemoveColumn
	@TableName nvarchar(100),
	@ColumnName nvarchar(100)
as
	begin
		declare @RemoveColumn nvarchar(max)
		set @RemoveColumn = 'alter table ' + QUOTENAME(@TableName) + ' drop column ' + 
		QUOTENAME(@ColumnName)

		exec sp_executesql @RemoveColumn
	end
go

exec uspRemoveColumn
	@TableName = 'Table',
	@ColumnName = 'Column2'

go

--c. add / remove a DEFAULT constraint;
--ADD DEFAULT CONSTRAINT
create or alter procedure uspAddDefaultConstraint
	@TableName nvarchar(100),
	@ColumnName nvarchar(100),
	@DefaultValue nvarchar(50)
as
	begin
		declare @AddDefault nvarchar(max)
		SET @AddDefault = 'ALTER TABLE ' + QUOTENAME(@TableName) + 
        ' ADD CONSTRAINT DF_' + @TableName + '_' + @ColumnName + 
        ' DEFAULT ' + @DefaultValue + ' FOR ' + QUOTENAME(@ColumnName)

		exec sp_executesql @AddDefault
	end
go

exec uspAddDefaultConstraint
	@TableName = 'Table',
	@ColumnName = 'Column',
	@DefaultValue = '0'
go

--DELETE DEFAULT CONSTRAINT
create or alter procedure uspDeleteDefaultConstraint
	@TableName nvarchar(100),
	@ColumnName nvarchar(100)
as
	begin
		declare @DeleteDefault nvarchar(max)
		set @DeleteDefault = 'alter table ' + QUOTENAME(@TableName) + ' drop constraint DF_' + 
		@TableName + '_' + @ColumnName

		exec sp_executesql @DeleteDefault
	end
go

exec uspDeleteDefaultConstraint
	@TableName = 'Table',
	@ColumnName = 'Column'
go

--d. add / remove a primary key;
--ADD PK
create or alter procedure uspAddPK
	@TableName nvarchar(100),
	@PKColumnName nvarchar(100)
as
	begin
		declare @AddPK nvarchar(max)
		set @AddPK = 'alter table ' + QUOTENAME(@TableName) + ' add constraint PK_' + 
		@TableName + ' primary key (' + QUOTENAME(@PKColumnName) + ')'

		exec sp_executesql @AddPK
	end
go

exec uspAddPK
	@TableName = 'Table',
	@PKColumnName = 'Column'
go

exec uspAddPK
	@TableName = 'TableForFK',
	@PKColumnName = 'ColumnForFK'
go

--DELETE PK
create or alter procedure uspDeletePK
	@TableName nvarchar(100),
	@ColumnName nvarchar(100)
as
	begin
		declare @DeletePK nvarchar(max)
		set @DeletePK = 'alter table ' + QUOTENAME(@TableName) + ' drop constraint PK_' + 
		@TableName

		exec sp_executesql @DeletePK
	end
go

exec uspDeletePK
	@TableName = 'Table',
	@ColumnName = 'Column'
go

--e. add / remove a candidate key;
--ADD CANDIDATE KEY
create or alter procedure uspAddCandidate
	@TableName nvarchar(100),
	@CDColumnName nvarchar(100)
as
	begin
		declare @AddCD nvarchar(max)
		set @AddCD = 'alter table ' + QUOTENAME(@TableName) + ' add constraint UQ_' +
		@TableName + ' unique (' + QUOTENAME(@CDColumnName) + ')'

		exec sp_executesql @AddCD
	end
go

exec uspAddCandidate
	@TableName = 'Table',
	@CDColumnName = 'Column2'
go

--DELETE CANDIDATE KEY
create or alter procedure uspDeleteCD
	@TableName nvarchar(100),
	@ColumnName nvarchar(100)
as
	begin
		declare @DeleteCD nvarchar(max)
		set @DeleteCD = 'alter table ' + QUOTENAME(@TableName) + ' drop constraint UQ_' + 
		@TableName

		exec sp_executesql @DeleteCD
	end
go

exec uspDeleteCD
	@TableName = 'Table',
	@ColumnName = 'Column2'
go

--f. add / remove a foreign key;
--ADD FK
create or alter procedure uspAddFK
	@TableName nvarchar(100),
	@ColumnName nvarchar(100),
	@TableForFK nvarchar(100),
	@ColumnForFK nvarchar(100)
as
	begin
		declare @AddFK nvarchar(max)
		set @AddFK = 'alter table ' + QUOTENAME(@TableName) + ' add constraint FK_' +
		@TableName + '_' + @TableForFK + ' foreign key (' + QUOTENAME(@ColumnName) +
		')' + ' references ' + QUOTENAME(@TableForFK) + '(' + QUOTENAME(@ColumnForFK) + ')'

		exec sp_executesql @AddFK
	end
go

exec uspAddFK
	@TableName = 'Table',
	@ColumnName ='Column',
	@TableForFK = 'TableForFK',
	@ColumnForFK = 'ColumnForFK'
go

--DELETE FK
create or alter procedure uspDeleteFK
	@TableName nvarchar(100),
	@TableForFK nvarchar(100)
as
	begin
		declare @DeleteFK nvarchar(max)
		set @DeleteFK = 'alter table ' + QUOTENAME(@TableName) + ' drop constraint FK_' +
		@TableName + '_' + @TableForFK 

		exec sp_executesql @DeleteFK
	end
go

exec uspDeleteFK
	@TableName = 'Table',
	@TableForFK = 'TableForFK'
go

--g. create / drop a table.
--CREATE TABLE
create or alter procedure uspCreateNewTable 
	@TableName nvarchar(100), 
	@ColumnName nvarchar(20),
	@NewType nvarchar(20)
as
	begin
		--Create a new table with the desired column type
		declare @CreateTable nvarchar(max)
		set @CreateTable = 'create table ' + QUOTENAME(@TableName) + ' (' +
		QUOTENAME(@ColumnName) + ' ' + QUOTENAME(@NewType) + ' )'

		exec sp_executesql @CreateTable

		declare @NotNull nvarchar(max)
		set @NotNull = 'alter table ' + QUOTENAME(@TableName) + ' alter column ' + 
		QUOTENAME(@ColumnName) + QUOTENAME(@NewType) +' not null'

		exec sp_executesql @NotNull
	end
go

exec uspCreateNewTable
	@TableName = 'Table',
	@ColumnName = 'Column',
	@NewType = 'INT'
go

exec uspCreateNewTable
	@TableName = 'TableForFK',
	@ColumnName = 'ColumnForFK',
	@NewType = 'INT'
go

--DROP TABLE
create or alter procedure uspDropTable
	@TableName nvarchar(100)
as
	begin
		--Drop the table
		declare @DropTable nvarchar(max)
		set @DropTable = 'drop table ' + QUOTENAME(@TableName)

		exec sp_executesql @DropTable
	end
go

exec uspDropTable
	@TableName = 'Table'
go

exec uspDropTable
	@TableName = 'TableForFK'
go

SELECT COLUMN_NAME, DATA_TYPE
FROM INFORMATION_SCHEMA.COLUMNS
WHERE TABLE_NAME = 'Table';

SELECT COLUMN_NAME, DATA_TYPE
FROM INFORMATION_SCHEMA.COLUMNS
WHERE TABLE_NAME = 'TableForFK';

select *
from INFORMATION_SCHEMA.COLUMNS
where TABLE_NAME = 'Table';

select *
from INFORMATION_SCHEMA.COLUMNS
where TABLE_NAME = 'TableForFK';

go
--Create a new table that holds the current version of the database schema. 
--Simplifying assumption: the version is an integer number.

--Write a stored procedure that receives as a parameter a version 
--number and brings the database to that version.

CREATE TABLE CurrentVersion
(currentVersion INT
)


INSERT CurrentVersion VALUES(0)

CREATE TABLE DataBaseVersions
(
VersionID INT PRIMARY KEY,
uspName VARCHAR(max),
ruspName VARCHAR(max),

)

INSERT DataBaseVersions VALUES(1,'uspCreateNewTable @TableName = ''Table'', @ColumnName = ''Column'', @NewType = ''SMALLINT''',
    'uspDropTable @TableName = ''Table''')
INSERT DataBaseVersions VALUES(2, 'uspModifyColumnType @TableName = ''Table'', @ColumnName = ''Column'', @NewType = ''INT''',
    'uspModifyColumnType @TableName = ''Table'', @ColumnName = ''Column'', @NewType = ''SMALLINT''')
INSERT DataBaseVersions VALUES(3,'uspAddColumn @TableName = ''Table'', @NewColumn = ''Column2'', @NewType = ''smallint''',
    'uspRemoveColumn @TableName = ''Table'', @ColumnName = ''Column2''')
INSERT DataBaseVersions VALUES(4,'uspAddDefaultConstraint @TableName = ''Table'', @ColumnName = ''Column'', @DefaultValue = ''0''',
    'uspDeleteDefaultConstraint @TableName = ''Table'', @ColumnName = ''Column''')
INSERT DataBaseVersions VALUES(5,'uspAddPK @TableName = ''Table'', @PKColumnName = ''Column''',
    'uspDeletePK @TableName = ''Table'', @ColumnName = ''Column''')
INSERT DataBaseVersions VALUES(6,'uspAddCandidate @TableName = ''Table'', @CDColumnName = ''Column2''',
    'uspDeleteCD @TableName = ''Table'', @ColumnName = ''Column2''')
INSERT DataBaseVersions VALUES(7, 'uspCreateNewTable @TableName = ''TableForFK'', @ColumnName = ''ColumnForFK'', @NewType = ''INT''',
    'uspDropTable @TableName = ''TableForFK''')
INSERT DataBaseVersions VALUES(8,'uspAddPK @TableName = ''TableForFK'', @PKColumnName = ''ColumnForFK''',
    'uspDeletePK @TableName = ''TableForFK'', @ColumnName = ''ColumnForFK''')
INSERT DataBaseVersions VALUES(9, 'uspAddFK @TableName = ''Table'', @ColumnName = ''Column'', @TableForFK = ''TableForFK'', @ColumnForFK = ''ColumnForFK''',
    'uspDeleteFK @TableName = ''Table'', @TableForFK = ''TableForFK''')
GO


GO
CREATE OR ALTER PROC uspDBVersion 
	@version INT
AS
BEGIN
	IF @version < 0 OR @version > (Select MAX(VersionID) FROM DataBaseVersions)
	BEGIN 
		RAISERROR ('There is no such version.',10,1)
		RETURN
	END
	DECLARE @currentDBVersion INT
	SET @currentDBVersion = (Select TOP(1) currentVersion FROM CurrentVersion)

	DECLARE @ExeProcedure VARCHAR(100)
	IF(@currentDBVersion < @version)
		WHILE(@currentDBVersion < @version)
		BEGIN
			SET @currentDBVersion = @currentDBVersion +1
			SET @ExeProcedure = (Select uspName FROM DataBaseVersions WHERE @currentDBVersion = VersionID)
			exec(@ExeProcedure)
		END
	ELSE IF(@currentDBVersion > @version)
			WHILE(@currentDBVersion > @version)
			BEGIN
				SET @ExeProcedure = (Select ruspName FROM DataBaseVersions WHERE @currentDBVersion = VersionID)
				SET @currentDBVersion = @currentDBVersion -1
				exec(@ExeProcedure)
			END

	UPDATE CurrentVersion
	SET currentVersion = @version
END
GO

EXEC uspDBVersion 9

select *
from DataBaseVersions

Select *
from CurrentVersion

drop table DataBaseVersions
drop table CurrentVersion

select *
from INFORMATION_SCHEMA.COLUMNS
where TABLE_NAME = 'Table';

select *
from INFORMATION_SCHEMA.COLUMNS
where TABLE_NAME = 'TableForFK';