CREATE TABLE student(
    student_id INTEGER,
    student_name TEXT,
    FOREIGN KEY(house_name)
);

CREATE TABLE house (
    house_id INTEGER,
    house_name TEXT,
    PRIMARY KEY(house_id)
);

CREATE TABLE head (
    head_id INTEGER,
    head_name TEXT,
    FOREIGN KEY(house_name)
    PRIMARY KEY(head_id)
);
