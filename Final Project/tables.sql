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
)