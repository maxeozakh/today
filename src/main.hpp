#pragma once

void get_rows_from_txt(const char *path, std::string *out_rows);
void split_rows_to_tasks_and_times(const std::string *rows, std::string *out_tasks, std::string *out_times);
void format_data_for_column(const std::string *raw_data, std::string *out_formatted_data, const int &column_length);
void *print_columns_as_rows(std::string *tasks, std::string *times);
void color_print(std::string &value, colors color);

