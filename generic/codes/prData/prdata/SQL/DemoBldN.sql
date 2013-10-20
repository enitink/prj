--
-- $Header: /plus/v4/spam/precious/files/ACTIVE/demobld.sql,v 1.1 1995/12/19 02:45:17 cjones Exp $
-- Copyright (c) Oracle Corporation 1988, 1993.  All Rights Reserved.
--
--
--   This script creates the SQL*Plus demonstration tables.
--
--   It should be STARTed by each user wishing to access the tables.
--

set termout on
prompt Building demonstration tables.  Please wait.
set termout off
set feedback off

ALTER SESSION SET NLS_LANGUAGE = AMERICAN;
ALTER SESSION SET NLS_TERRITORY = AMERICA;

DROP TABLE EMP;
DROP TABLE DEPT;
DROP TABLE BONUS;
DROP TABLE SALGRADE;
DROP TABLE DUMMY;

CREATE TABLE EMP
       (EMPNO NUMBER(4) NOT NULL,
        ENAME VARCHAR2(10),
        JOB VARCHAR2(9),
        MGR NUMBER(4),
        HIREDATE DATE,
        SAL NUMBER(7,2),
        COMM NUMBER(7,2),
        DEPTNO NUMBER(2));

INSERT INTO EMP VALUES
        (7369,'SMITH','CLERK',7902,'17-DEC-80',800,NULL,20);
INSERT INTO EMP VALUES
        (7499,'ALLEN','SALESMAN',7698,'20-FEB-81',1600,300,30);
INSERT INTO EMP VALUES
        (7521,'WARD','SALESMAN',7698,'22-FEB-81',1250,500,30);
INSERT INTO EMP VALUES
        (7566,'JONES','MANAGER',7839,'2-APR-81',2975,NULL,20);
INSERT INTO EMP VALUES
        (7654,'MARTIN','SALESMAN',7698,'28-SEP-81',1250,1400,30);
INSERT INTO EMP VALUES
        (7698,'BLAKE','MANAGER',7839,'1-MAY-81',2850,NULL,30);
INSERT INTO EMP VALUES
        (7782,'CLARK','MANAGER',7839,'9-JUN-81',2450,NULL,10);
INSERT INTO EMP VALUES
        (7788,'SCOTT','ANALYST',7566,'09-DEC-82',3000,NULL,20);
INSERT INTO EMP VALUES
        (7839,'KING','PRESIDENT',NULL,'17-NOV-81',5000,NULL,10);
INSERT INTO EMP VALUES
        (7844,'TURNER','SALESMAN',7698,'8-SEP-81',1500,0,30);
INSERT INTO EMP VALUES
        (7876,'ADAMS','CLERK',7788,'12-JAN-83',1100,NULL,20);
INSERT INTO EMP VALUES
        (7900,'JAMES','CLERK',7698,'3-DEC-81',950,NULL,30);
INSERT INTO EMP VALUES
        (7902,'FORD','ANALYST',7566,'3-OCT-81',3000,NULL,20);
INSERT INTO EMP VALUES
        (7934,'MILLER','CLERK',7782,'20-JUL-82',1300,NULL,10);
INSERT INTO EMP VALUES
        (7777,'JOHN','ANALYST',7902,'3-JUN-85',3300,NULL,20);
INSERT INTO EMP VALUES
        (7776,'SHUSAN','ANALYST',7902,'31-JAN-83',3300,200,20);
INSERT INTO EMP VALUES
        (7778,'SMONTY','SALESMAN',7566,'13-FEB-80',3300,10,20);
INSERT INTO EMP VALUES
        (7779,'JOHNATHAN','CLERK',7902,'23-JAN-81',3300,NULL,20);
INSERT INTO EMP VALUES
        (7994,'MILTON','MANAGER',7839,'30-JUL-82',2300,100,40);
INSERT INTO EMP VALUES
        (7977,'JOHNSON','ANALYST',7994,'25-JUN-83',3300,NULL,40);
INSERT INTO EMP VALUES
        (7976,'SHUSIE','ANALYST',7994,'21-AUG-87',2900,1000,40);
INSERT INTO EMP VALUES
        (7978,'SMARTY','SALESMAN',7994,'29-NOV-81',3000,100,40);
INSERT INTO EMP VALUES
        (7979,'ANDREW','CLERK',7994,'27-AUG-84',1300,NULL,40);
        
CREATE TABLE DEPT
       (DEPTNO NUMBER(2),
        DNAME VARCHAR2(14),
        LOC VARCHAR2(13) );

INSERT INTO DEPT VALUES
        (10,'ACCOUNTING','NEW YORK');
INSERT INTO DEPT VALUES (20,'RESEARCH','DALLAS');
INSERT INTO DEPT VALUES
        (30,'SALES','CHICAGO');
INSERT INTO DEPT VALUES
        (40,'OPERATIONS','BOSTON');

CREATE TABLE BONUS
        (
        ENAME VARCHAR2(10),
        JOB VARCHAR2(9),
        SAL NUMBER,
        COMM NUMBER
        );

CREATE TABLE SALGRADE
      ( GRADE NUMBER,
        LOSAL NUMBER,
        HISAL NUMBER );

INSERT INTO SALGRADE VALUES (1,700,1200);
INSERT INTO SALGRADE VALUES (2,1201,1400);
INSERT INTO SALGRADE VALUES (3,1401,2000);
INSERT INTO SALGRADE VALUES (4,2001,3000);
INSERT INTO SALGRADE VALUES (5,3001,9999);

CREATE TABLE DUMMY
      ( DUMMY NUMBER );

INSERT INTO DUMMY VALUES (0);

COMMIT;

EXIT;
