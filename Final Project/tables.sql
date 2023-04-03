CREATE TABLE staff (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name TEXT NOT NULL,
    seniority TEXT NOT NULL,
    performance_level TEXT NOT NULL,
    shift TEXT NOT NULL
);

CREATE TABLE counters (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    counter_name TEXT NOT NULL,
    selling_point TEXT NOT NULL,
    position TEXT NOT NULL,
    position_experience TEXT NOT NULL,
    morning_service_hours TEXT NOT NULL,
    late_service_hours TEXT NOT NULL,
    night_service_hours TEXT NOT NULL
);

CREATE TABLE schedule (
    active_counters TEXT NOT NULL,
    active_staff TEXT NOT NULL,
    date TEXT NOT NULL,
    weekday TEXT NOT NULL,
    FOREIGN KEY (active_counters)
    REFERENCES counters (id),
    FOREIGN KEY (active_staff)
    REFERENCES staff (id)
);


INSERT INTO counter (id, counter_name, selling_point, level, morning_service_hours, late_service_hours, night_service_hours) VALUES (1, "V02", "IBERIA", "max", "6:30-14:30", "14:30-22:30", "22:30-6:30");

SELECT * FROM schedule JOIN counters ON schedule.active_counters = counters.id JOIN staff ON schedule.active_staff = staff.id;