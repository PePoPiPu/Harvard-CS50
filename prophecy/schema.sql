CREATE TABLE students(
    id INTEGER,
    student_name TEXT
    PRIMARY KEY(id)
);

CREATE TABLE houses (
    id INTEGER,
    house_name TEXT,
    head_name TEXT
    PRIMARY KEY(id)
);

CREATE TABLE assignments (
    student_id INTEGER,
    head_name TEXT,
    house_id INTEGER,
    FOREIGN KEY(student_id) REFERENCES students(id),
    FOREIGN KEY (head_name) REFERENCES houses(head_name),
    FOREIGN KEY (house_id) REFERENCES house(id)
);