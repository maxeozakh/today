#include <iostream>
#include <fstream>
#include <string>

void get_rows_from_txt(const char *path, std::string *out_rows);
void split_rows_to_tasks_and_times(const std::string *rows,
								   std::string *out_tasks,
								   std::string *out_times);
void format_data_for_column(const std::string *raw_data,
							std::string *out_formatted_data,
							const int &column_length);

int main()
{
	const int max_rows = 100;

	std::string rows[max_rows];
	get_rows_from_txt("../assets/tasks.txt", rows);

	std::string tasks[max_rows], times[max_rows];
	split_rows_to_tasks_and_times(rows, tasks, times);

	std::string formatted_tasks[max_rows], formatted_times[max_rows];
	format_data_for_column(tasks, formatted_tasks, 30);
	format_data_for_column(times, formatted_times, 5);

	std::cout << "🐕" << '\n';
}

void format_data_for_column(const std::string *raw_data, std::string *out_formatted_data, const int &column_length)
{
	std::string row, formatted_row;
	while (*raw_data != "")
	{
		row = *raw_data;
		int additional_spaces_count = column_length - row.length();

		if (additional_spaces_count < 0)
		{
			std::cout << "oooooops, raw row is too long, dont wanna format that \n";
			additional_spaces_count = 0;
		}

		formatted_row = row.append(additional_spaces_count, ' ');
		std::cout << formatted_row << '\n';
		raw_data++;
	}
}

/*
const char *make_row(const char *task_text,
					 const char *task_time,
					 const char *routine_text,
					 const char *routine_time);
void print_rows(const char *tasks_text,
				const char *tasks_time,
				const char *routinies_text,
				const char *routinies_time);

task-text --- t-time --- r-text --- r-time 
*/

void split_rows_to_tasks_and_times(const std::string *rows, std::string *out_tasks, std::string *out_times)
{
	std::string row, task, time, divider = "--t";

	while (*rows != "")
	{
		row = *rows;
		int divider_position = row.find(divider);

		task = row.substr(0, divider_position - 1);
		time = row.substr(divider_position + divider.length() + 1);

		*out_tasks = task;
		*out_times = time;

		rows++;
		out_tasks++;
		out_times++;
	}
}

void get_rows_from_txt(const char *path, std::string *out_rows)
{
	std::string line;
	std::ifstream file(path);

	if (!file.is_open())
	{
		std::cout << "oops something really bad happens when trying to read file in path - " << path << '\n';
	}
	else
	{
		while (file.good())
		{
			std::getline(file, line);
			*out_rows = line;
			out_rows++;
		}
	}
}