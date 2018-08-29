USE master
GO
drop database ѧ��ѡ�ο�

USE [yjp]
GO

/****** Object:  Table [dbo].[�γ�]    Script Date: 2015-10-26 15:01:30 ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

SET ANSI_PADDING ON
GO
primary
CREATE TABLE [dbo].[�γ�](
	[�γ̺�] [char](5) NOT NULL,
	[�γ���] [char](20) NULL,
	[���п�] [char](5) NULL,
	[ѧʱ] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[�γ̺�] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO

SET ANSI_PADDING OFF
GO




CREATE DATABASE ѧ��ѡ�ο�
ON PRIMARY
  ( NAME='ѧ��ѡ�����ļ�',
   FILENAME=
      'd:\ѡ�����ļ�.mdf',
   SIZE=10,
   MAXSIZE=100,
   FILEGROWTH=10MB),
FILEGROUP ѧ��ѡ�δ��ļ���
  ( NAME = 'ѧ��ѡ�δ��ļ�1',
   FILENAME =
      'd:\ѧ��ѡ�δ��ļ�1.ndf',
   SIZE = 1MB,
   MAXSIZE=10,
   FILEGROWTH=10%),
  ( NAME = 'ѧ��ѡ�δ��ļ�2',
   FILENAME =
      'd:\ѧ��ѡ�δ��ļ�2.ndf',
   SIZE = 1MB,
   MAXSIZE=10,
   FILEGROWTH=1)
LOG ON
  ( NAME='ѧ��ѡ�ο���־',
   FILENAME =
      'd:\ѧ��ѡ����־.ldf',
   SIZE=1,
   MAXSIZE=10,
   FILEGROWTH=1)
GO

ALTER DATABASE ѧ��ѡ�ο�
MODIFY FILEGROUP [ѧ��ѡ�δ��ļ���] DEFAULT
GO
ALTER DATABASE ѧ��ѡ�ο�
MODIFY FILEGROUP [primary] DEFAULT
GO


USE ѧ��ѡ�ο�

drop database ѧ��ѡ�ο�


CREATE TABLE ѡ��
  ( id  int   PRIMARY KEY,
   ѧ��      char(10),
   �γ̺�   char(8),
   �ɼ�     smallint
 ) ON ѧ��ѡ�δ��ļ���
GO
 
create table ����(
  ���� smallint identity(1,1) primary key clustered,
  ���� varchar(50) not null,
  ������ char(8)

)

create table ְ��(
 ���� smallint Primary key clustered,
 ���� char(8),
 �������� smallmoney,
 ���ӹ��� smallmoney,
 ʵ������ as ��������+���ӹ���,
 ���Ŵ��� smallint references ����(����),
 �Ա� char(2) default '��' check(�Ա� in ('��','Ů'))
 )

alter table ѡ��
    alter column �ɼ� smallint not null;

alter table ѡ��
    add  constraint �ɼ�Լ��  check(�ɼ� between 0 and 100);

alter  table ѡ��  add  �Ա� char(2) default '��' ,check(�Ա� in ('��','Ů'))

create table ѧ��(
    ѧ�� int identity(1,1) primary key,
	�Ա� char(2) check(�Ա� in('��','Ů')),
	���� int

)
alter table ѧ�� add constraint Ĭ���Ա� default 20 for �Ա�


alter table ѡ�� nocheck constraint CK__ѡ��__�Ա�__1920BF5C;


alter table ѡ�� drop constraint CK__ѡ��__�Ա�__1920BF5C;
alter table ѡ�� drop constraint DF__ѡ��__�Ա�__182C9B23

alter table ѡ��  drop column �Ա�;

create unique index ְ���� on ְ��(����)

drop index ְ��.ְ����

create unique index ְ���� on ְ��(���� asc) with pad_index ,fillfactor=10,
   ignore_dup_key,statistics_norecompute on ѧ��ѡ�δ��ļ���;

IGNORE_DUP_KEY

���Ƶ�����������Ψһ�ۼ��������в����ظ��ļ�ֵʱ����������������Ϊ����ָ���� IGNORE_DUP_KEY������ִ���˴����ظ����� INSERT ��䣬SQL Server ������������Ϣ�������ظ����С�

STATISTICS_NORECOMPUTE

ָ�����ڵ�����ͳ�Ʋ����Զ����¼��㡣��Ҫ�ָ��Զ�����ͳ�ƣ���ִ��û�� NORECOMPUTE �Ӿ�� UPDATE STATISTICS��

��Ҫ  ������÷ֲ�ͳ�Ƶ��Զ����¼��㣬���ܻ���� SQL Server ��ѯ�Ż���Ϊ�漰�ñ�Ĳ�ѯѡȡ���ִ�мƻ���

update STATISTICS ְ�� 
EXEC sp_autostats ְ��, 'ON'
alter index ְ���� on ְ�� rebuild with (statistics_norecompute=on)

drop index ְ��.ְ����

create view ְ������1
  as select * from ְ�� with check option 

create view ְ������
  with encryption
  as select * from ְ�� with check option

  drop view ְ������2

create view ְ������2
  with schemabinding
  as select ����,�������� from dbo.ְ�� with check option

  drop table ְ��

create unique clustered index ְ�����ʺ� on ְ������2(����)

drop view ְ������2


create default Ĭ�ϻ������� as 500
exec sp_bindefault 'Ĭ�ϻ�������','ְ��.��������'
exec sp_unbindefault  'ְ��.��������','Ĭ�ϻ�������'

drop default Ĭ�ϻ�������

create rule �������ʹ��� as @range>=$100 and @range<=1000

create rule �Ա� as @sex in ('��','Ů')

exec sp_bindrule '�������ʹ���','ְ��.��������'

exec sp_unbindrule 'ְ��.��������','�������ʹ���' 

drop rule �Ա�


create procedure ��ѯȫ��ѧ��
   as select * from dbo.ѧ��

exec ��ѯȫ��ѧ��

drop procedure ��ѯȫ��ѧ��


create procedure ��ѯѧ��
 @id smallint
 as
   begin 
   select * from ѧ�� where ѧ��=@id
   select * from ѧ�� where ѧ��=@id+1
   end 

exec ��ѯѧ�� '2'

drop procedure ��ѯѧ��

create trigger ��ѯ on ְ��
  with encryption
  for insert
  as select * from ְ��

drop trigger ��ѯ

select * from ְ��

insert into ְ�� values('314','��˼',20,'Ů')

select * from ѧ��

begin transaction
update ѧ�� set ����=����+1
select * from ѧ��

rollback transaction

create trigger ¼��ְ�� on ְ��
    for insert
    as if (select count(*)
            from ����,inserted
            where inserted.���Ŵ���=����.����         
          )<1
           rollback transaction

select * from ����


drop trigger ¼��ְ��
 
create trigger ¼��ְ��1 on ְ��
    after insert
    as if (select count(*)
            from ����,inserted
            where inserted.���Ŵ���=����.����         
          )>0
           rollback transaction

drop trigger ¼��ְ��

 
create trigger ¼��ְ�� on ְ��
    instead of insert
    as if (select count(*)
            from ����,inserted
            where inserted.���Ŵ���=����.����         
          )>0
           rollback transaction

create trigger ɾ������ on ����
     for delete
     as if (select count(*)
        from ְ��,deleted
        where ְ��.���Ŵ���=deleted.����)>0
          rollback transaction
        else
           delete ����
            from ����,deleted
            where ����.����=deleted.����

delete from ���� where ����.����=1


CREATE TRIGGER member_delete  ON member
         FOR DELETE
         AS IF (SELECT COUNT(*)
              FROM loan��deleted
              WHERE loan.member_no=deleted.member_no)>0
              ROLLBACK TRANSACTION
            ELSE
               DELETE reservation 
               From reservation,deleted
               where reservation.member_no=deleted.member_no              



insert into ���� values('�����','��˾')

insert into ְ�� values(1,'����',500,500,1,'��')

drop trigger ��ѯ

insert into ְ�� values(2,'����',500,500,1,'��')

declare @id int
declare @���� char(8)
set @id=100
set @����='����'
print @id
print @����
go 

declare @���� char(8)
set @����=(select top 1 ���� from ѧ��)
select @����
go

declare @minichengji  int
select @minichengji=min(�ɼ�) from ѡ�� where �ɼ� is not null
print @minichengji



declare @t table(id int identity,col varchar(4))
declare @sql varchar(60)
set @sql='������������Τ�����ŷ����һ��������ĳ��ӵ����'
declare @i int;
set @i=1
declare @n int;
set @n=2 --����ֶγ���
while(@i<len(@sql))
begin
    insert into @t select substring(@sql,@i,@n)
    set @i=@i+@n
end
select * from @t
go 

declare @ѧ������  table(
       ѧ�� char(5) not null unique,
       ���� char(8) not null,
      ���� smallint default 20,
      �Ա� char(2),
      ����ϵ char(20))
insert into  @ѧ������ select ѧ��,����,����,�Ա�,����ϵ  from ѧ��
select * from  @ѧ������
go

print @@language
go 

print @@version
go

print 'ĿǰSQL Server����������Ϊ��'+@@SERVERNAME
go
print 'Ŀǰ���÷�����Ϊ��'+@@SERVICENAME
go

insert into table_1 values('��')
print @@identity
go

update ѧ�� set ����=����+1
print @@rowcount
go

select * from ѧ��3
go
print @@error
go

declare @���� char(8)
select @����=����
 from ѧ��
 where ѧ��=1
print @����
go

declare @id int
set @id=cast('1111' as int)
print @id
go

SELECT 'ѧ��:'+cast(ѧ�� as char(5))+'������'+ ����+ '���䣺' + CAST(���� AS varchar(4))
FROM ѧ��


GO


declare @date1 datetime
set @date1=cast('12/7/1999' as datetime)
print @date1
go

declare @date2 datetime
set @date2=convert(datetime,'12-7-1999')
print @date2
go


declare @date2 datetime
set @date2=convert(datetime,'12-7-1999  9:10:50:333 PM')
declare @date3 char(30)
set @date3=convert(char(30),@date2,109)
print @date3
go

declare @date2 datetime
set @date2=convert(smalldatetime,'12-7-1999')
declare @date3 char(20)
set @date3=convert(char(20),@date2,104)
print @date3
go



if (
    select count(*)
     from ѧ��
)>2
begin
 print 'ѧ����������2'
end
else
begin
print 'ѧ������С�ڵ���2'
end
go

declare @countid int
set @countid=0
while (@countid<10)
begin
 set @countid=@countid+1
 print @countid
end
go

declare @countid int
set @countid=0
while (@countid<10)
begin
set @countid=@countid+1
if @countid=5   continue
if @countid=9   break
print @countid
end

DECLARE @s int,@times int  
set @s=1
set @times=1
label1:
set @s=@s*@times
set @times=@times+1
if @times<=10
    goto label1
print '���Ϊ:'+str(@s)

/*
  ע��
*/
--ע��
go

declare @countid int
set @countid=0
while (@countid<10)
begin
 set @countid=@countid+1
if @countid=5
  return
 print @countid
end

select  ѧ��,�γ̺�,�ɼ�=case 
                  when �ɼ�>60 then '����'
                   else '������' 
                   end
from ѡ��



declare ȫ��ѧ����ѯ scroll cursor  for select * from ѧ��
open ȫ��ѧ����ѯ
fetch next from ȫ��ѧ����ѯ
fetch first from ȫ��ѧ����ѯ
fetch last from ȫ��ѧ����ѯ
close ȫ��ѧ����ѯ

create table #��ʱ��
(id int,
 name char(8)
)

create table ##ȫ����ʱ��
(id int,
 name char(8)
)

print db_name()
print host_name()
print suser_ID()
print suser_name()
print user_ID()
print user_name()

print dateadd(mm,3,sysdatetime())
print datediff(d,cast('2015-01-01' as datetime),sysdatetime())

SELECT DATEPART(month, GETDATE())  AS  'Month Number'

SELECT MONTH('03/12/1998'), DAY('03/12/1998'),YEAR('03/12/1998')

create function student()
returns TABLE
as 
  return(select * from ѧ��);

drop function student

select * from student()

create function student1(@id int)
returns char(10)
as 
   begin
     return (select ���� from ѧ�� where ѧ�� = @id)
   end

select dbo.student1(1)

drop function student1