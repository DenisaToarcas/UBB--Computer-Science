
DECLARE @VolunteersAddPK TABLE(volunteer_id INT primary key,
volunteer_name VARCHAR(50),
volunteer_cnp CHAR(13),
volunteer_Faculty_id INT foreign key references Faculties(faculty_id),
volunteer_BirthDate DATE,
volunteer_EnrolmentDate DATE,
volunteer_BC BIT,
volunteer_is_presindent_of_OSUBB BIT,
volunteer_department_id INT foreign key references Departments(department_id))

UPDATE Volunteers
SET volunteer_is_presindent_of_OSUBB = 1
OUTPUT inserted.volunteer_id, inserted.volunteer_name, inserted.volunteer_is_presindent_of_OSUBB, deleted.volunteer_is_presindent_of_OSUBB, SUSER_SNAME(), GETDATE()
INTO @VolunteersAddPK
WHERE Volunteers.volunteer_id = 5
GO
-----------------------------------------------------------------

declare @FacultiesModified TABLE(
faculty_id INT primary key,
faculty_name VARCHAR(100),
faculty_address VARCHAR(300),
faculty_date_of_construction DATE,
faculty_specialization_name VARCHAR(100)
)

UPDATE Faculties
SET faculty_address = 'street Kogalniceanu, no. 20'
OUTPUT inserted.faculty_id, inserted.faculty_name, deleted.faculty_address, inserted.faculty_address, SUSER_SNAME() as 'USER', GETDATE() as 'TIME MODIFIED'
WHERE faculty_address like 'Avram Iancu street'
GO
---------------------------------------------------------------

CREATE or ALTER PROCEDURE dbo.uspModifyColumnType
    @TableName NVARCHAR(128),
    @ColumnName NVARCHAR(128),
    @NewDataType NVARCHAR(50)
AS
BEGIN
    DECLARE @NewTableName NVARCHAR(128) = @TableName + '_Temp';

    -- Step 1: Create a new table with the desired column type
    DECLARE @SqlCreateTable NVARCHAR(MAX);
    SET @SqlCreateTable = '
        CREATE TABLE ' + QUOTENAME(@NewTableName) + ' (
            -- List all columns except the one being modified
            ';
    
    SELECT @SqlCreateTable += COLUMN_NAME + ' ' + DATA_TYPE + ',' 
    FROM INFORMATION_SCHEMA.COLUMNS
    WHERE TABLE_NAME = @TableName AND COLUMN_NAME != @ColumnName;

    SET @SqlCreateTable += '
            ' + QUOTENAME(@ColumnName) + ' ' + @NewDataType + '
        )
    ';
    
    EXEC sp_executesql @SqlCreateTable;

    -- Step 2: Copy data from the old table to the new table
    DECLARE @SqlInsertData NVARCHAR(MAX);
    SET @SqlInsertData = '
        INSERT INTO ' + QUOTENAME(@NewTableName) + ' (
            -- List all columns except the one being modified
            ';

    SELECT @SqlInsertData += COLUMN_NAME + ',' 
    FROM INFORMATION_SCHEMA.COLUMNS
    WHERE TABLE_NAME = @TableName AND COLUMN_NAME != @ColumnName;

    SET @SqlInsertData += '
            ' + QUOTENAME(@ColumnName) + '
        )
        SELECT
            -- List all columns except the one being modified
            ';

    SELECT @SqlInsertData += COLUMN_NAME + ',' 
    FROM INFORMATION_SCHEMA.COLUMNS
    WHERE TABLE_NAME = @TableName AND COLUMN_NAME != @ColumnName;

    SET @SqlInsertData += '
            CAST(' + QUOTENAME(@ColumnName) + ' AS ' + @NewDataType + ')
        FROM ' + QUOTENAME(@TableName);
    
    EXEC sp_executesql @SqlInsertData;

    -- Step 3: Drop the old table
    DECLARE @SqlDropTable NVARCHAR(MAX);
    SET @SqlDropTable = 'DROP TABLE ' + QUOTENAME(@TableName);
    EXEC sp_executesql @SqlDropTable;

    -- Step 4: Rename the new table to the original table name
    EXEC sp_rename @NewTableName, @TableName;

END
GO

-- Execute the stored procedure to modify the column type
EXEC dbo.uspModifyColumnType 
    @TableName = 'YourTableName', 
    @ColumnName = 'YourColumnName', 
    @NewDataType = 'new_data_type';
 
