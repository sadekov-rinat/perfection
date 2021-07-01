DROP TABLE solution;
DROP TABLE solution_component;
DROP TABLE requirement;
DROP TABLE solution_requirement;
DROP TABLE component;
DROP TABLE component_capability;
DROP TABLE component_domain;
DROP TABLE component_type;
DROP TABLE program;
DROP TABLE programming_language;
DROP TABLE program_language;
DROP TABLE device;
DROP TABLE user_roles;
DROP TABLE user_groups;
DROP TABLE sessions;
DROP TABLE users;

CREATE TABLE "solution" (
  "id" SERIAL PRIMARY KEY,
  "name" varchar
);

CREATE TABLE "solution_component" (
  "id" SERIAL PRIMARY KEY,
  "solution_id" int,
  "used_by" int,
  "name" varchar
);

CREATE TABLE "requirement" (
  "id" SERIAL PRIMARY KEY,
  "name" varchar,
  "description" varchar,
  "requirement_category_id" int
);

CREATE TABLE "solution_requirement" (
  "id" SERIAL PRIMARY KEY,
  "solution_id" int,
  "exprassion" varchar
);

CREATE TABLE "component" (
  "id" SERIAL PRIMARY KEY,
  "component_domain_id" varchar,
  "component_type_id" varchar,
  "device_id" int,
  "program_id" int,
  "group" varchar,
  "version" varchar,
  "name" varchar,
  "description" varchar
);

CREATE TABLE "component_capability" (
  "id" SERIAL PRIMARY KEY,
  "component_id" int,
  "name" varchar,
  "description" varchar,
  "exprassion" varchar
);

CREATE TABLE "component_domain" (
  "uid" varchar PRIMARY KEY
);

CREATE TABLE "component_type" (
  "uid" varchar PRIMARY KEY
);

CREATE TABLE "program" (
  "id" SERIAL PRIMARY KEY,
  "name" varchar
);

CREATE TABLE "programming_language" (
  "id" SERIAL PRIMARY KEY,
  "name" varchar
);

CREATE TABLE "program_language" (
  "id" SERIAL PRIMARY KEY,
  "program_id" int,
  "programming_language_id" int
);

CREATE TABLE "device" (
  "id" SERIAL PRIMARY KEY,
  "name" varchar,
  "consumption" integer,
  "mass" integer,
  "min_temperature" integer,
  "max_temperature" integer,
  "electromagnetic_protection" boolean,
  "radiological_protection" boolean
);

CREATE TABLE "user_roles" (
  "id" SERIAL PRIMARY KEY,
  "roles_type" varchar
);

CREATE TABLE "user_groups" (
  "id" SERIAL PRIMARY KEY,
  "group_names" varchar
);

CREATE TABLE "sessions" (
  "id" SERIAL PRIMARY KEY,
  "start_time" date,
  "close_time" date,
  "session_hash" varchar,
  "login" varchar
);

CREATE TABLE "users" (
  "id" SERIAL PRIMARY KEY,
  "surname" varchar,
  "department" varchar,
  "login" varchar,
  "pass_hash" varchar,
  "tel" varchar,
  "email" varchar,
  "groups" varchar,
  "role" varchar,
  "note" varchar
);

ALTER TABLE "solution_component" ADD FOREIGN KEY ("solution_id") REFERENCES "solution" ("id");
ALTER TABLE "solution_component" ADD FOREIGN KEY ("id") REFERENCES "component" ("id");
ALTER TABLE "component" ADD FOREIGN KEY ("component_domain_id") REFERENCES "component_domain" ("uid");
ALTER TABLE "component" ADD FOREIGN KEY ("program_id") REFERENCES "program" ("id");
ALTER TABLE "component" ADD FOREIGN KEY ("device_id") REFERENCES "device" ("id");
ALTER TABLE "solution_component" ADD FOREIGN KEY ("used_by") REFERENCES "solution_component" ("id");
ALTER TABLE "program_language" ADD FOREIGN KEY ("program_id") REFERENCES "program" ("id");
ALTER TABLE "program_language" ADD FOREIGN KEY ("programming_language_id") REFERENCES "programming_language" ("id");
ALTER TABLE "component" ADD FOREIGN KEY ("component_type_id") REFERENCES "component_type" ("uid");
ALTER TABLE "component_capability" ADD FOREIGN KEY ("component_id") REFERENCES "component" ("id");
ALTER TABLE "solution_requirement" ADD FOREIGN KEY ("id") REFERENCES "requirement" ("id");
ALTER TABLE "solution_requirement" ADD FOREIGN KEY ("solution_id") REFERENCES "solution" ("id");
ALTER TABLE "sessions" ADD FOREIGN KEY ("login") REFERENCES "users" ("login");
ALTER TABLE "users" ADD FOREIGN KEY ("groups") REFERENCES "user_roles" ("roles_type");
ALTER TABLE "users" ADD FOREIGN KEY ("role") REFERENCES "user_groups" ("group_names");

