CREATE TABLE students (
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
    student_id INTEGER NOT NULL,
    head_name TEXT NOT NULL,
    house_id INTEGER NOT NULL,
    FOREIGN KEY(student_id) REFERENCES students(id),
    FOREIGN KEY (head_name) REFERENCES houses(head_name),
    FOREIGN KEY (house_id) REFERENCES house(id)
);