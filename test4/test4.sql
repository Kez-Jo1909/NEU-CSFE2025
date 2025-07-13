CREATE DATABASE MyDB;

USE MyDB;

CREATE TABLE Stu (
    Sno CHAR(20) PRIMARY KEY,
    Sname CHAR(10),
    Gender CHAR(2),
    Age INT,
    Birthday DATE,
    Class CHAR(10)
);

 CREATE TABLE Course (
    Cno CHAR(2) PRIMARY KEY,
    Cname CHAR(10),
    Chour INT
);

CREATE TABLE Score (
    Sno CHAR(20),
    Cno CHAR(2),
    Grade INT,
    PRIMARY KEY (Sno, Cno),
    FOREIGN KEY (Sno) REFERENCES Stu(Sno),
    FOREIGN KEY (Cno) REFERENCES Course(Cno)
);SELECT Stu.Sname, Course.Cname, Score.Grade FROM Score JOIN Stu ON Score.Sno = Stu.Sno JOIN Course ON Score.Cno = Course.Cno;M

INSERT INTO Stu VALUES('','','男',20,'','');
INSERT INTO Stu VALUES('','','男',20,'','');
INSERT INTO Stu VALUES('','','男',20,'','');

INSERT INTO Course VALUES ('01', '数据库', 32);
INSERT INTO Course VALUES ('02', '高数', 48);
INSERT INTO Course VALUES ('03', '英语', 64);

INSERT INTO Score VALUES ('', '01', 85);
INSERT INTO Score VALUES ('', '01', 56);
INSERT INTO Score VALUES ('', '02', 76);
INSERT INTO Score VALUES ('', '03', 86);
INSERT INTO Score VALUES ('', '02', 46);
INSERT INTO Score VALUES ('', '03', 66);
INSERT INTO Score VALUES ('', '03', 88);
INSERT INTO Score VALUES ('', '02', 88);
INSERT INTO Score VALUES ('', '01', 68);

SELECT Sno, Sname, Birthday FROM Stu;

SELECT Class, Sname FROM Stu WHERE Class = '' ORDER BY Sno;

SELECT Stu.Sname, Course.Cname, Score.Grade FROM Score JOIN Stu ON Score.Sno = Stu.Sno JOIN Course ON Score.Cno = Course.Cno;

SELECT Stu.Sname, Course.Cname, Score.Grade FROM Score JOIN Stu ON Score.Sno = Stu.Sno JOIN Course ON Score.Cno = Course.Cno;

SELECT DISTINCT Stu.Sno, Sname, Class FROM Score JOIN Stu ON Score.Sno = Stu.Sno WHERE Grade < 60;

SELECT Stu.Sname, AVG(Grade) AS PJCJ, SUM(Grade) AS ZCJ FROM Score JOIN Stu ON Score.Sno = Stu.Sno GROUP BY Stu.Sname;

SELECT Stu.Sname, Stu.Class FROM Stu WHERE NOT EXISTS (SELECT * FROM Course WHERE Course.Cno NOT IN (SELECT Score.Cno FROM Score WHERE Score.Sno = Stu.Sno AND Score.Grade >= 85));

UPDATE Course SET Cname = '软件技术' WHERE Cno = '01';

UPDATE Stu SET Sname = '' WHERE Sname = '';

UPDATE Score SET Grade = 60 WHERE Grade BETWEEN 55 AND 59 AND Sno IN (SELECT Sno FROM Stu WHERE Gender = '男');

SELECT * FROM Course;

SELECT * FROM Stu;

SELECT * FROM Score;

DELETE FROM Score WHERE Sno IN (SELECT Sno FROM Stu WHERE YEAR(Birthday) > 2001 OR YEAR(Birthday) < 1999);

DELETE FROM Stu WHERE YEAR(Birthday) > 2001 OR YEAR(Birthday) < 1999;


DELETE FROM Score WHERE Sno IN (SELECT Sno FROM Stu WHERE Class = '' );

DELETE FROM Stu WHERE Class = '';

DROP TABLE Score;

DROP TABLE Course;

DROP DATABASE MyDB;
