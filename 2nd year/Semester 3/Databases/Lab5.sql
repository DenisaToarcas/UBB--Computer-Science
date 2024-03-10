
go
CREATE OR ALTER PROCEDURE insertTestData
    @TableName NVARCHAR(255),
    @NumberOfRows INT
AS
BEGIN
    DECLARE @Columns NVARCHAR(MAX);
    DECLARE @Values NVARCHAR(MAX);
    DECLARE @Sql NVARCHAR(MAX);
    DECLARE @Counter INT = 1;

    DECLARE @colName VARCHAR
    (100);
    DECLARE @colDatatype VARCHAR
    (100);

    DECLARE @DynamicSQL NVARCHAR(MAX);
    DECLARE @DynamicResult NVARCHAR(MAX);
    DECLARE @ForeignKeyTable VARCHAR(100);

    DECLARE curDatatype cursor
    FOR SELECT column_name, data_type
    FROM information_schema.columns
    WHERE table_name=@TableName
    ORDER BY ORDINAL_POSITION;

    WHILE @Counter <= @NumberOfRows
    BEGIN

        OPEN curDatatype;

        SET @Columns = '';
        SET @Values = '';

        FETCH NEXT FROM curDatatype INTO @colName, @colDatatype;
        WHILE @@FETCH_STATUS = 0
        BEGIN
            SET @ForeignKeyTable = (SELECT
                KCU2.TABLE_NAME
            FROM
                INFORMATION_SCHEMA.REFERENTIAL_CONSTRAINTS RC
                JOIN
                INFORMATION_SCHEMA.KEY_COLUMN_USAGE KCU1
                ON RC.CONSTRAINT_NAME = KCU1.CONSTRAINT_NAME
                JOIN
                INFORMATION_SCHEMA.KEY_COLUMN_USAGE KCU2
                ON RC.UNIQUE_CONSTRAINT_NAME = KCU2.CONSTRAINT_NAME
            WHERE 
                                        KCU1.TABLE_NAME = @TableName
                AND KCU1.COLUMN_NAME = @colName);

            SET @DynamicResult = '';
            IF @ForeignKeyTable != ''
                BEGIN
                SET @DynamicSQL = '
        SET @DynamicResult += (SELECT TOP 1 ' + QUOTENAME(@colName) + ' 
                               FROM ' + QUOTENAME(@ForeignKeyTable) + ');';
                EXEC sp_executesql @DynamicSQL, N'@DynamicResult NVARCHAR(MAX) OUTPUT', @DynamicResult OUTPUT;
            END


            SET @Columns = @Columns + @colName + ', ';
            SET @Values = @Values +
                    CASE 
                        WHEN @colDatatype IN ('int', 'smallmoney', 'tinyint', 'mediumint') THEN
                        CASE
                            WHEN @ForeignKeyTable != '' THEN @DynamicResult
                            ELSE CAST(@Counter AS NVARCHAR(MAX))
                        END  
                        WHEN @colDatatype = 'varchar' THEN '''' + LEFT(CAST(NEWID() AS NVARCHAR(MAX)), 20) + ''''
                        WHEN @colDatatype = 'datetime' THEN '''' + CONVERT(NVARCHAR(MAX), DATEADD(DAY, ABS(CHECKSUM(NEWID())) % (DATEDIFF(DAY, '1753-01-01', '9999-12-31') + 1), '1753-01-01'), 120) + ''''
                        WHEN @colDatatype = 'decimal' THEN CAST(@Counter % 5 + 1 AS NVARCHAR(MAX))
                        ELSE NULL
                    END + ', ';

            FETCH NEXT FROM curDatatype INTO @colName, @colDatatype;
        END

        CLOSE curDatatype;

        SET @Columns = LEFT(@Columns, LEN(@Columns) - 1);
        SET @Values = LEFT(@Values, LEN(@Values) - 1);

        SET @Sql = 'INSERT INTO ' + @TableName + ' (' + @Columns + ') ' + 'SELECT ' + @Values;

        -- PRINT(@Sql)

        EXEC sp_executesql @Sql;

        SET @Counter = @Counter + 1;
    END

    DEALLOCATE curDatatype
END;

alter table Sponsor_Project
add sponsor_projectPK int primary key

alter table Sponsors
add s2 int unique

alter table Projects
add p2 int

exec insertTestData
	@TableName = 'Projects',
	@NumberOfRows = 100
go

exec insertTestData
	@TableName = 'Sponsors',
	@NumberOfRows = 100
go

exec insertTestData
	@TableName = 'Sponsor_Project',
	@NumberOfRows = 100
go

select *
from Sponsors

select *
from Projects

select *
from Sponsor_Project

delete from Sponsors
delete from Projects
delete from Sponsor_Project

--Clustered indexe:
--	In a clustered index, the rows of the table are physically sorted on the disk 
--based on the order of the index key.
--	There can be only one clustered index per table because the physical order of the 
--data can only be based on one key.
--	The primary key of a table is often used to define the clustered index by default, 
--but it can be defined on any unique column.
--	Due to the physical sorting, the data pages themselves are the index pages. 
--	This means that the leaf level of the clustered index is the actual data.

--Non-Clustered Index:
--	In a non-clustered index, a separate structure is created to store the index data,
--and the actual data rows are stored separately from the index.
--	There can be multiple non-clustered indexes per table.
--	The leaf level of the non-clustered index contains pointers to the actual 
--data rows in the table.

--Work on 3 tables of the form Ta(aid, a2, …), Tb(bid, b2, …), Tc(cid, aid, bid, …), where:

--aid, bid, cid, a2, b2 are integers;
--the primary keys are underlined;
--a2 is UNIQUE in Ta;
--aid and bid are foreign keys in Tc, referencing the primary keys in Ta and Tb, respectively.

--a. Write queries on Ta such that their execution plans contain the following operators:

--clustered index scan;
select *
from Sponsors

select *
from Sponsors
order by sponsor_id

--clustered index seek;
select *
from Sponsors
where sponsor_id < 50

--nonclustered index scan;
select top 10 s2
from Sponsors

--nonclustered index seek;
select s2
from Sponsors
where s2 = 2

--key lookup
select s2, sponsor_name
from Sponsors
where s2 = 2

--b. Write a query on table Tb with a WHERE clause of the form WHERE b2 = value and analyze its execution plan. 
--Create a nonclustered index that can speed up the query. Examine the execution plan again.

select p2
from Projects
where p2 = 50

create index N_TProjects_p2 on Projects(p2);
go

drop index N_TProjects_p2 on Projects

--c. Create a view that joins at least 2 tables. 
--Check whether existing indexes are helpful; if not, reassess existing indexes / examine the cardinality of the tables.

go
create view testViewProjects
as
	select Projects.project_name
	from Projects
	inner join Sponsor_Project
	on Projects.project_id = Sponsor_Project.project_id
go

select *
from testViewProjects

create index N_Sponsor_Project on Sponsor_Project(project_id)
go

drop index N_Sponsor_Project on Sponsor_Project


---------------------------------------------------------------------------------------------------
-- Check indexes on Projects
--EXEC sp_helpindex 'Projects';

-- Check indexes on Sponsor_Project
--EXEC sp_helpindex 'Sponsor_Project';

--they are helpful


-----------------------------------------------------------------------------------------------------

-- Assess cardinality of columns in Projects
--SELECT COUNT(DISTINCT project_id) AS Cardinality_Projects
--FROM Projects;

-- Assess cardinality of columns in Sponsor_Project
--SELECT COUNT(DISTINCT project_id) AS Cardinality_Sponsor_Project
--FROM Sponsor_Project;
