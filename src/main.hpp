#pragma once
std::string color_codes[] = {"97", "92"};
enum colors
{
        grey,
        green
};

std::string flag_codes[] = {"-c", "-f"};

enum flags
{
        check,
        fail,
};

void clear_screen();
void input_and_render_loop(const char *file_path);
void render(const char *file_path);
void get_rows_from_txt(const char *path, std::string *out_rows);
void split_rows_to_tasks_and_times(const std::string *rows, std::string *out_tasks, std::string *out_times);
void format_data_for_column(const std::string *raw_data, std::string *out_formatted_data, const int &column_length);
void print_columns_as_rows(std::string *tasks, std::string *times);
void color_print(std::string &value, colors color);
void insert_string_to_the_line(const char *file_path, const int &line_number, std::string inserted_string);
std::string get_line_by_line_number(const char *file_path, const int &line_number);
void add_flag_to_the_line(const char *file_path, const int &line_number, std::string &flag);
