CREATE TABLE EMP20 (EMP_CODE CHAR(5) PRIMARY KEY, EMP_NAME CHAR(20), DEPT_CODE CHAR(5), DESIG_CODE CHAR(5), SEX CHAR(1), ADDRESS CHAR(25), CITY CHAR(20), STATE CHAR(20), PIN CHAR(6), BASIC NUMBER, JN_DT DATE);
CREATE TABLE DESIGNATION20 (DESIG_CODE CHAR(5) PRIMARY KEY, DESIG_DESC CHAR(20));
CREATE TABLE DEPARTMENT20 (DEPT_CODE CHAR(5) PRIMARY KEY, DEPT_NAME CHAR(15));

DESCRIBE EMP20;
DESCRIBE DESIGNATION20;
DESCRIBE DEPARTMENT20;

SELECT * FROM DESIGNATION20;
SELECT * FROM DEPARTMENT20;
SELECT * FROM EMP20;

INSERT INTO DEPARTMENT20 VALUES('D1','PERSONNEL');
INSERT INTO DEPARTMENT20 VALUES('D2','PRODUCTION');
INSERT INTO DEPARTMENT20 VALUES('D3','PURCHASE');
INSERT INTO DEPARTMENT20 VALUES('D4','FINANCE');
INSERT INTO DEPARTMENT20 VALUES('D5','RESEARCH');

INSERT INTO DESIGNATION20 VALUES('DE1','MANAGER');
INSERT INTO DESIGNATION20 VALUES('DE2','EXECUTIVE');
INSERT INTO DESIGNATION20 VALUES('DE3','OFFICER');
INSERT INTO DESIGNATION20 VALUES('DE4','CLERK');
INSERT INTO DESIGNATION20 VALUES('DE5','HELPER');

INSERT INTO EMP20 VALUES('E1','ABC','D1','DE1','M','12, IFYGUK','KOLKATA','WEST BENGAL','700023',12000,TO_DATE('17/12/2000', 'DD/MM/YYYY'));
INSERT INTO EMP20 VALUES('E2','DEF','D2','DE1','M','12, IFGUK','KOLKATA','WEST BENGAL','700033',20000,TO_DATE('15/02/2000', 'DD/MM/YYYY'));
INSERT INTO EMP20 VALUES('E3','GHI','D1','DE4','F','12, YGUK','KOLKATA','WEST BENGAL','700043',140000,TO_DATE('16/08/2002', 'DD/MM/YYYY'));
INSERT INTO EMP20 VALUES('E4','KLM','D3','DE5','M','12, GUK','KOLKATA','WEST BENGAL','700073',10000,TO_DATE('17/06/2005', 'DD/MM/YYYY'));

INSERT INTO EMP20 (EMP_CODE, EMP_NAME, DESIG_CODE, SEX, ADDRESS, CITY, STATE, PIN, JN_DT) VALUES('E5','KLMN', 'DE5', 'M','12, GUKDFG','KOLKATA','WEST BENGAL','700073',TO_DATE('12/06/2005', 'DD/MM/YYYY'));
INSERT INTO EMP20 (EMP_CODE, EMP_NAME, DESIG_CODE, SEX, ADDRESS, CITY, STATE, PIN, JN_DT) VALUES('E6','KLMDSFSN', 'DE1', 'F','16, DDAFG','KOLKATA','WEST BENGAL','700063',TO_DATE('15/08/2010', 'DD/MM/YYYY'));
INSERT INTO EMP20 (EMP_CODE, EMP_NAME, DESIG_CODE, SEX, ADDRESS, CITY, STATE, PIN, JN_DT) VALUES('E7','KFSLMN', 'DE3', 'M','15, YEFD','KOLKATA','WEST BENGAL','700013',TO_DATE('01/06/2011', 'DD/MM/YYYY'));

SELECT * FROM EMP20 WHERE DEPT_CODE IS NULL;

INSERT INTO EMP20 VALUES('E8','JGH','D3','DE5','M','12, GUK','KOLKATA','WEST BENGAL','700073',0,TO_DATE('17/06/2005', 'DD/MM/YYYY'));
INSERT INTO EMP20 VALUES('E9','ZXC','D3','DE5','M','12, GUWEFK','KOLKATA','WEST BENGAL','700073',0,TO_DATE('20/06/2010', 'DD/MM/YYYY'));
INSERT INTO EMP20 VALUES('E10','XIAO','D5','DE5','M','12, GUWEFK','KOLKATA','WEST BENGAL','700073',0,TO_DATE('20/01/1989', 'DD/MM/YYYY'));
INSERT INTO EMP20 VALUES('E11','ZHANG','D5','DE5','M','12, GUWEFK','KOLKATA','WEST BENGAL','700073',0,TO_DATE('18/01/1987', 'DD/MM/YYYY'));

SELECT * FROM EMP20 WHERE BASIC=0;

SELECT * FROM EMP20 WHERE BASIC IS NULL;

SELECT AVG(BASIC) FROM EMP20;

UPDATE EMP20 SET BASIC=0 WHERE BASIC IS NULL;

SELECT AVG(BASIC) FROM EMP20;

DELETE FROM EMP20 WHERE DEPT_CODE IS NULL;

SELECT EMP_NAME, BASIC + 0.5*BASIC+ 0.4*BASIC AS NETPAY FROM EMP20;

SELECT UPPER(EMP_NAME), BASIC FROM EMP20 ORDER BY DEPT_CODE;

SELECT * FROM EMP20 WHERE JN_DT>=TO_DATE('01/01/1990', 'DD/MM/YYYY');

SELECT * FROM EMP20 WHERE JN_DT;

SELECT MAX(BASIC), MIN(BASIC) FROM EMP20;

SELECT COUNT(*) FROM EMP20 WHERE SEX='F';

INSERT INTO EMP20 VALUES('E12','ZHANG','D5','DE5','F','12, GUWEFK','MUMBAI','MAHARASHTRA','700073',0,TO_DATE('18/01/1987', 'DD/MM/YYYY'));
INSERT INTO EMP20 VALUES('E13','ZHANG','D5','DE5','F','12, GUWEFK','BANGALORE','WEST BENGAL','700073',0,TO_DATE('18/01/1987', 'DD/MM/YYYY'));

UPDATE EMP20 SET CITY=UPPER(CITY);

SELECT COUNT(DISTINCT CITY) FROM EMP20;

SELECT * FROM EMP20 ORDER BY DEPT_CODE, BASIC DESC;





#ASSIGNMENT 2

SELECT DEPT_CODE,MIN(BASIC),MAX(BASIC), AVG(BASIC) FROM EMP20 GROUP BY DEPT_CODE;

SELECT DEPT_CODE,COUNT(*) FROM EMP20 WHERE SEX='F' GROUP BY DEPT_CODE;

SELECT CITY,DEPT_CODE, COUNT(*) FROM EMP20 GROUP BY CITY,DEPT_CODE;

SELECT DESIG_CODE,DEPT_CODE,COUNT(*) AS C FROM EMP20 WHERE JN_DT>=TO_DATE('01/01/2000', 'DD/MM/YYYY') AND JN_DT<=TO_DATE('31/12/2000', 'DD/MM/YYYY') GROUP BY DESIG_CODE,DEPT_CODE ORDER BY C;

#######SELECT DEPT_CODE, SUM(BASIC) AS B FROM EMP20 WHERE SEX='M' GROUP BY DEPT_CODE ORDER BY B DESC;

SELECT E.EMP_NAME, D.DESIG_DESC, E.BASIC FROM EMP20 E, DESIGNATION20 D WHERE E.DESIG_CODE=D.DESIG_CODE;

SELECT E.EMP_NAME, D.DESIG_DESC, DE.DEPT_NAME, E.BASIC FROM EMP20 E, DESIGNATION20 D, DEPARTMENT20 DE WHERE E.DESIG_CODE=D.DESIG_CODE AND DE.DEPT_CODE=E.DEPT_CODE;

SELECT DE.DEPT_CODE FROM DEPARTMENT20 DE WHERE (SELECT COUNT(*) FROM EMP20 WHERE EMP20.DEPT_CODE=DE.DEPT_CODE)=0;

SELECT DE.DEPT_NAME FROM DEPARTMENT20 DE WHERE (SELECT COUNT(*) FROM EMP20 WHERE EMP20.DEPT_CODE=DE.DEPT_CODE)>=1;

SELECT DE.DEPT_NAME FROM DEPARTMENT20 DE WHERE (SELECT COUNT(*) FROM EMP20 WHERE EMP20.DEPT_CODE=DE.DEPT_CODE)>=10;

SELECT DEPT_CODE FROM EMP20 WHERE BASIC= (SELECT MAX(BASIC) FROM EMP20);

SELECT D.DESIG_DESC FROM DESIGNATION20 D WHERE D.DESIG_CODE=(SELECT DESIG_CODE FROM EMP20 WHERE BASIC= (SELECT MAX(BASIC) FROM EMP20));

SELECT E.DEPT_CODE, COUNT(*) FROM EMP20 E WHERE E.DESIG_CODE=(SELECT DE.DESIG_CODE FROM DESIGNATION20 DE WHERE DE.DESIG_DESC='MANAGER') GROUP BY E.DEPT_CODE; 

######## NO 13






INSERT INTO EMP20 VALUES('E14','ABC','D1','DE7','M','12, IFYGUK','ASANSOL','WEST BENGAL','700023',12000,TO_DATE('15/12/2000', 'DD/MM/YYYY'));
INSERT INTO EMP20 VALUES('E15','ABC','D1','DE8','M','12, IFYGUK','ASANSOL','WEST BENGAL','700023',12000,TO_DATE('15/12/2000', 'DD/MM/YYYY'));
INSERT INTO EMP20 VALUES('E16','ABC','D1','DE9','M','12, IFYGUK','ASANSOL','WEST BENGAL','700023',12000,TO_DATE('15/12/2000', 'DD/MM/YYYY'));

# NO 20
SELECT COUNT(*) FROM EMP20 E WHERE E.DESIG_CODE=(SELECT DE.DESIG_CODE FROM DESIGNATION20 DE WHERE DE.DESIG_DESC='MANAGER') AND E.SEX='F'; 








