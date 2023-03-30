CREATE TABLE staff (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name TEXT NOT NULL,
    seniority TEXT NOT NULL,
    performance_level TEXT NOT NULL,
    shift TEXT NOT NULL
);

CREATE TABLE counter (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    counter_name TEXT NOT NULL,
    selling_point TEXT NOT NULL,
    level TEXT NOT NULL,
    morning_service_hours TEXT NOT NULL,
    late_service_hours TEXT NOT NULL,
    night_service_hours TEXT NOT NULL
);

CREATE TABLE schedule (
    active_counters INTEGER NOT NULL,
    active_staff INTEGER NOT NULL,
    shift TEXT NOT NULL,
    date TEXT NOT NULL,
    weekday TEXT NOT NULL,
    FOREIGN KEY (active_counters),
    REFERENCES counter (id)
    FOREIGN KEY (active_staff),
    REFERENCES staff (id),
    FOREIGN KEY (shift),
    REFERENCES staff (shift)
)