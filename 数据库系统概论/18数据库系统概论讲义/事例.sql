drop database   yjp;
create database yjp;
use yjp;
create table ѧ��(
   ѧ�� char(5) not null unique,
   ���� char(8) not null,
   ���� smallint default 20,
   �Ա� char(2),
   ����ϵ char(20),
   constraint c2 check(�Ա� in ('��','Ů') )
   );
drop table ѧ��

create Table �γ�(
   �γ̺� char(5) primary Key,
   �γ��� char(20),
   ���п� char(5) 

);

create Table ѡ��(
   ѧ�� char(5),
   �γ̺� char(5),
   �ɼ� smallint,
   constraint c3 check(�ɼ� between 0 and 100),
   constraint c4 primary key(ѧ��,�γ̺�),
   constraint c5 Foreign key(ѧ��) references ѧ��(ѧ��),
   constraint c6 Foreign key (�γ̺�) references �γ�(�γ̺�)
);

alter table �γ� add ѧʱ  smallint;

alter table �γ� add ѧʱ1  smallint,ѧʱ2 smallint;

alter table �γ� alter column ѧʱ int;

alter table ѧ�� drop c2;

alter table �γ� drop column ѧʱ2,ѧʱ1;

alter table ѧ�� add constraint c2 check(�Ա� in ('��','Ů') );

alter table ѡ�� drop c3;

alter table ѡ�� alter column �ɼ� int not null;


create unique index ѧ�� on ѧ��(ѧ��);

drop index ѧ��.ѧ��;

create unique index ѡ�κ� on �γ�(�γ̺�);

drop index �γ�.ѡ�κ�;

create clustered index ѧ�� on ѧ��(ѧ��); 

create unique index ѡ�κ� on ѡ��(ѧ�� asc,�γ̺� desc);

create view �ɼ���(ѧ��,����,�γ���,�ɼ�)
  as select ѧ��.ѧ��,ѧ��.����,�γ�.�γ���,ѡ��.�ɼ�
      from ѧ��,�γ�,ѡ��
        where ѧ��.ѧ��=ѡ��.ѧ�� and �γ�.�γ̺�=ѡ��.�γ̺�

select * from �ɼ���;
select * from �ɼ��� where �ɼ� is not null;
select * from �ɼ��� where �ɼ� >=80;


create view ѧ���ɼ�(ѧ��,����,�γ���,�ɼ�,����ϵ)
  as select ѧ��.ѧ��,ѧ��.����,�γ�.�γ���,ѡ��.�ɼ�,ѧ��.����ϵ
      from ѧ��,�γ�,ѡ��
        where ѧ��.ѧ��=ѡ��.ѧ�� and �γ�.�γ̺�=ѡ��.�γ̺� and ѧ��.����ϵ='�����ϵ'

drop view ѧ���ɼ�;

select * from ѧ���ɼ�;

create view ѧ���ɼ���(ѧ��,�ܳɼ�,ƽ���ɼ�)
  as select ѧ��,sum(�ɼ�),avg(�ɼ�)
   from ѡ��
   group by ѧ��

select * from ѧ���ɼ���







select ѧ��,����
   from ѧ��
     where ����ϵ='�����ϵ';

select ѧ�� from ѡ��;

select distinct ѧ�� from ѡ��;

select all ѧ�� from ѡ��;



select ѧ��,�ɼ�
   from ѡ��
   where �γ̺�='2'
    order by �ɼ� desc,ѧ�� asc;


select ѧ��,�ɼ�*0.8
  from ѡ��
   where �γ̺�='2' and �ɼ� between 82 and 99;

select ѧ�� as ѧ�����,�ɼ�*1.1 as ����,'���' as �ον�ʦ
  from ѡ��
   where �γ̺�='2' and �ɼ� between 60 and 90;


select * 
from ѧ��
where ����ϵ in ('�����ϵ','��Ϣϵ') and ���� like 'Ǯ%'

select * 
from ѧ��
where ����ϵ in ('�����ϵ','��Ϣϵ') and ���� like 'Ǯ_'

select * 
from ѧ��
where ����ϵ in ('�����ϵ','��Ϣϵ') and ���� like '%��'

select * 
from ѧ��
where (����ϵ='�����ϵ' or ����ϵ='��Ϣϵ') and ���� like '%��'


select ѧ��,�γ̺�
from ѡ��
where �ɼ� is null;

select ѧ��,�γ̺�,�ɼ�
from ѡ��
where �ɼ� is not Null;


select  ѧ��,�γ̺�,�ɼ�
from ѡ��
where �ɼ� <> '';

update ѡ��
set �ɼ�=�ɼ�-1

select * from ѡ��

select ѧ��.*,ѡ��.*
  from ѧ��,ѡ��
  where ѧ��.ѧ��=ѡ��.ѧ��;


select ѧ��.ѧ�� as ѧ������ ,���� as ѧ������,�γ���,�ɼ�
from ѧ��,�γ�,ѡ��
where ѧ��.ѧ��=ѡ��.ѧ�� and ѡ��.�γ̺�=�γ�.�γ̺�

select * from �γ�

select a.�γ̺�,a.�γ���,b.�γ���
from �γ� a,�γ� b
where a.���п�=b.�γ̺�

select  a.�γ̺�,a.�γ���,��һ���п�=b.�γ���,c.�γ��� as �ڶ����п�
from �γ� a,�γ� b,�γ� c
where a.���п�=b.�γ̺� and b.���п�=c.�γ̺�

select ѧ��.ѧ��,����,ѡ��.�γ̺�  as ��ѡ��,�ɼ�
from ѧ��,ѡ��
 where ѧ��.ѧ��*=ѡ��.ѧ��

select ѧ��, ѡ��.�γ̺�,�γ���
from ѡ��,�γ�
where ѡ��.�γ̺�=*�γ�.�γ̺� 


select a.�γ̺�,a.�γ���,b.�γ���
from �γ� a left join �γ� b on a.���п�=b.�γ̺�


select  a.�γ̺�,a.�γ���,b.�γ��� as ��һ���п�,c.�γ��� as �ڶ����п�
from �γ� a left join �γ� b on a.���п�=b.�γ̺� left join �γ� c on b.���п�=c.�γ̺�


select ѧ��,����
from ѧ��
where ѧ�� in (select ѧ��
               from ѡ��
               where �γ̺�=(
                           select �γ̺�
                             from �γ�
                             where �γ���='���ݿ�'
                            ))

select ѧ��,�ɼ�
from ѡ��
where �γ̺�='2' and  �ɼ�>(
                        select �ɼ�
                         from ѡ��
                         where �γ̺�='2' and ѧ��=(select ѧ�� 
                                                       from ѧ�� 
                                                       where ����='Ǯ��') 
                             )
select *
from ѧ��
where ����< any(select ���� from ѧ�� where ����ϵ='�����ϵ') and  ����ϵ<>'��Ϣϵ';

select *
from ѧ��
where ����< all(select ���� from ѧ�� where ����ϵ='�����ϵ') and  ����ϵ<>'��Ϣϵ';

select ѧ��,����
from ѧ��
where exists (select *
               from ѡ��
              where ѧ��.ѧ��=ѡ��.ѧ�� and �γ̺�='2'
              )

select ����
from ѧ��
where not exists(
           select *
           from ѡ��
           where ѧ��.ѧ��=ѧ�� and �γ̺�='2'
)

select ѧ��, ���� 
from ѧ��
where not exists (
           select *
           from �γ�
           where not exists(select *
                 from ѡ��
                 where ѧ��.ѧ��=ѧ�� and �γ�.�γ̺�=�γ̺�
                            )
                  )

select ѧ��, ����
from ѧ��
where not exists(select *
                 from ѡ�� a
                 where a.ѧ��='2' and  not exists(select *
                                                     from ѡ�� b
                                                      where ѧ��.ѧ��=b.ѧ�� and a.�γ̺�=b.�γ̺�
                                                     )
    
               )

select ѧ��
from ѡ��
where �γ̺�='2'
union
select ѧ��
from ѡ��
where �γ̺�='3'

select ѡ��.ѧ��
from ѡ��,(select ѡ��1.ѧ�� from ѡ�� ѡ��1 where ѡ��1.�γ̺�='3') sc
where ѡ��.ѧ��=sc.ѧ�� and ѡ��.�γ̺�='2'


select ѧ��
from ѡ��
where �γ̺�='2'
union all
select ѧ��
from ѡ��
where �γ̺�='3'


select count(*)
from ѧ��

select count(distinct ѧ��)
from ѡ��;

select �γ̺�,count(ѧ��) as ѡ������
from ѡ��
group by �γ̺�;

select  ѧ��,count(�γ̺�) as ѡ����
from ѡ��
group by ѧ��;

select ѧ��,count(�γ̺�) as ѡ����
from ѡ��
group by ѧ�� having count(*)>3;


insert 
into ѧ��
values('9','�ž�',20,'��','�����ϵ')

insert into ѡ��(ѧ��,�γ̺�)
values('9','1')

create table ƽ���ɼ�(ѧ�� char(5),ƽ���ɼ� smallint);
insert
into ƽ���ɼ�
select ѧ��,avg(�ɼ�)
from ѡ��
group by ѧ��

drop table ƽ���ɼ�; 

select ѧ��,avg(�ɼ�) as ƽ���ɼ�
into ƽ���ɼ�
from ѡ��
group by ѧ��;

update ѡ��
set �ɼ�=�ɼ�*0.9
where �γ̺�=(select �γ̺�
              from �γ�
              where �γ���='���ݿ�'
             )


update ѡ��
set �ɼ�=�ɼ�/0.9
where '���ݿ�'=(select �γ���
               from �γ�
               where ѡ��.�γ̺�=�γ�.�γ̺�
               )

delete from ѡ�� where ѧ��='9';
delete from ѧ�� where ѧ��='9';

delete from ѡ��
where ѧ�� in (select ѧ��
               from ѧ��
               where ����ϵ='��Ϣϵ')

grant create table to yang

revoke create table from yang

grant select on ѧ��(ѧ��,����) to yang with grant option

grant select on ѧ�� to yang with grant option

revoke grant option for select  on ѧ��  from yang cascade

revoke select on ѧ�� from  yang

grant all on ѡ�� to yjp

grant update(�ɼ�) on ѡ�� to yjp
revoke update(�ɼ�) on ѡ�� from yjp

revoke all on ѡ�� from yjp

update ѡ��
set �ɼ�=�ɼ�+1

revoke all on ѡ�� from yang
deny all on ѡ�� to yang

select ѡ��1.ѧ��
from ѡ�� ѡ��1,ѡ�� ѡ��2
where ѡ��1.�γ̺�='2' and ѡ��2.�γ̺�='3' and ѡ��1.�ɼ�>ѡ��2.�ɼ� and ѡ��1.ѧ��=ѡ��2.ѧ��