//
// Created by hliangzhao on 2022/4/2.
//

#include <cstdio>
#include <cstring>

struct Student {
    char SID[15];
    int CID;
    char name[15];
    int scores[5];
} students[105];

// 全局变量，记录了当前学生总数
int cur_stu_num = 0;
char input[15];
int input_class_ID;

void menu() {
    printf("\nWelcome to Student Performance Management System (SPMS).\n\n");
    printf("1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show statistics\n0 - Exit\n\n");
}

int main() {
    // TODO: 还没测试
    menu();
    int choice;
    while (scanf("%d", &choice) == 1 && choice != 0) {
        if (choice == 1) {
            while (true) {
                // TODO：声明并初始化一个结构体变量
                Student s{};
                printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
                scanf("%s", s.SID);
                if (strlen(s.SID) == 1 && s.SID[0] == '0') break;
                // 将剩下的6个字段读入
                scanf("%d", &s.CID);
                scanf("%s", s.name);
                for (int i = 0; i < 4; i++) {
                    scanf("%d", &s.scores[i]);
                }
                // 检查SID是否重复，如果重复则输出duplicate信息
                int found = 0;
                for (int i = 0; i < cur_stu_num; i++) {
                    if (strcmp(s.SID, students[i].SID) == 0) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    printf("Duplicated SID.\n");
                    continue;
                } else {
                    // 将这个记录插入数据库
                    students[cur_stu_num++] = s;
                }
            }
            menu();
        } else if (choice == 2) {
            while (true) {
                int removed_num = 0;
                printf("Please enter SID or name. Enter 0 to finish.\n");
                scanf("%s", input);
                if (strlen(input) == 1 && input[0] == '0') break;
                // 尝试匹配input所指示的SID或name
                for (int i = 0; i < cur_stu_num; i++) {
                    if (strcmp(students[i].SID, input) == 0 || strcmp(students[i].name, input) == 0) {
                        removed_num++;
                        // 将从i+1开始的记录全部前移
                        for (int j = i + 1; j < cur_stu_num; j++) {
                            students[j - 1] = students[j];
                        }
                    }
                }
                cur_stu_num -= removed_num;
                printf("%d student(s) removed.\n", removed_num);
            }
            menu();
        } else if (choice == 3) {
            while (true) {
                int rank = 1, total_score = 0;
                double average_score;
                printf("Please enter SID or name. Enter 0 to finish.\n");
                scanf("%s", input);
                if (strlen(input) == 1 && input[0] == '0') break;
                // 尝试匹配input所指示的SID或name
                for (int i = 0; i < cur_stu_num; i++) {
                    if (strcmp(students[i].SID, input) == 0 || strcmp(students[i].name, input) == 0) {
                        // 计算总分和均分
                        for (int j = 0; j < 4; j++) {
                            total_score += students[i].scores[j];
                        }
                        average_score = (double) total_score / 4.0;
                        // 计算排名
                        for (int k = 0; k < cur_stu_num; k++) {
                            int cur_stu_total_score = 0;
                            for (int j = 0; j < 4; j++) {
                                cur_stu_total_score += students[k].scores[j];
                            }
                            if (total_score < cur_stu_total_score) {
                                rank++;
                            }
                        }
                        // 打印
                        printf("%s %d %d %.2lf\n", input, rank, total_score, average_score);
                    }
                }
            }
            menu();
        } else if (choice == 4) {
            printf("Showing the ranklist hurts students\' self-esteem. Don\'t do that.\n");
            menu();
        } else if (choice == 5) {
            while (true) {
                double c_aver = 0, m_aver = 0, e_aver = 0, p_aver = 0;
                int c_passed = 0, m_passed = 0, e_passed = 0, p_passed = 0;
                int all_passed = 0, three_passed = 0, two_passed = 0, one_passed = 0, all_failed = 0;
                printf("Please enter class ID, 0 for the whole statistics.\n");
                scanf("%d", &input_class_ID);
                if (input_class_ID == 0) {
                    // 显示整个年级的统计信息，然后终止
                    for (int i = 0; i < cur_stu_num; i++) {
                        int passed_num_of_cur_s = 0;
                        c_aver += students[i].scores[0];
                        if (students[i].scores[0] >= 60) {
                            c_passed++;
                            passed_num_of_cur_s++;
                        }
                        m_aver += students[i].scores[1];
                        if (students[i].scores[1] >= 60) {
                            m_passed++;
                            passed_num_of_cur_s++;
                        }
                        e_aver += students[i].scores[2];
                        if (students[i].scores[2] >= 60) {
                            e_passed++;
                            passed_num_of_cur_s++;
                        }
                        p_aver += students[i].scores[3];
                        if (students[i].scores[3] >= 60) {
                            p_passed++;
                            passed_num_of_cur_s++;
                        }
                        if (passed_num_of_cur_s == 4) {
                            all_passed++;
                            three_passed++;
                            two_passed++;
                            one_passed++;
                        } else if (passed_num_of_cur_s == 3) {
                            three_passed++;
                            two_passed++;
                            one_passed++;
                        } else if (passed_num_of_cur_s == 2) {
                            two_passed++;
                            one_passed++;
                        } else if (passed_num_of_cur_s == 1) {
                            one_passed++;
                        } else {
                            all_failed++;
                        }
                    }
                    c_aver /= 4.0;
                    m_aver /= 4.0;
                    e_aver /= 4.0;
                    p_aver /= 4.0;

                    printf("Chinese\n");
                    printf("Average Score: %.2lf\n", c_aver);
                    printf("Number of passed students: %d\n", c_passed);
                    printf("Number of failed students: %d\n\n", cur_stu_num - c_passed);

                    printf("Mathematics\n");
                    printf("Average Score: %.2lf\n", m_aver);
                    printf("Number of passed students: %d\n", m_passed);
                    printf("Number of failed students: %d\n\n", cur_stu_num - m_passed);

                    printf("English\n");
                    printf("Average Score: %.2lf\n", e_aver);
                    printf("Number of passed students: %d\n", e_passed);
                    printf("Number of failed students: %d\n\n", cur_stu_num - e_passed);

                    printf("Programming\n");
                    printf("Average Score: %.2lf\n", p_aver);
                    printf("Number of passed students: %d\n", p_passed);
                    printf("Number of failed students: %d\n\n", cur_stu_num - p_passed);

                    printf("Overall:\n");
                    printf("Number of students who passed all subjects: %d\n", all_passed);
                    printf("Number of students who passed 3 or more subjects: %d\n", three_passed);
                    printf("Number of students who passed 2 or more subjects: %d\n", two_passed);
                    printf("Number of students who passed 1 or more subjects: %d\n", one_passed);
                    printf("Number of students who failed all subjects: %d\n", all_failed);

                    break;
                } else {
                    // 显示指定班级的信息
                    for (int i = 0; i < cur_stu_num; i++) {
                        if (input_class_ID == students[i].CID) {
                            int passed_num_of_cur_s = 0;
                            c_aver += students[i].scores[0];
                            if (students[i].scores[0] >= 60) {
                                c_passed++;
                                passed_num_of_cur_s++;
                            }
                            m_aver += students[i].scores[1];
                            if (students[i].scores[1] >= 60) {
                                m_passed++;
                                passed_num_of_cur_s++;
                            }
                            e_aver += students[i].scores[2];
                            if (students[i].scores[2] >= 60) {
                                e_passed++;
                                passed_num_of_cur_s++;
                            }
                            p_aver += students[i].scores[3];
                            if (students[i].scores[3] >= 60) {
                                p_passed++;
                                passed_num_of_cur_s++;
                            }
                            if (passed_num_of_cur_s == 4) {
                                all_passed++;
                                three_passed++;
                                two_passed++;
                                one_passed++;
                            } else if (passed_num_of_cur_s == 3) {
                                three_passed++;
                                two_passed++;
                                one_passed++;
                            } else if (passed_num_of_cur_s == 2) {
                                two_passed++;
                                one_passed++;
                            } else if (passed_num_of_cur_s == 1) {
                                one_passed++;
                            } else {
                                all_failed++;
                            }
                        }
                    }
                    c_aver /= 4.0;
                    m_aver /= 4.0;
                    e_aver /= 4.0;
                    p_aver /= 4.0;

                    printf("Chinese\n");
                    printf("Average Score: %.2lf\n", c_aver);
                    printf("Number of passed students: %d\n", c_passed);
                    printf("Number of failed students: %d\n\n", cur_stu_num - c_passed);

                    printf("Mathematics\n");
                    printf("Average Score: %.2lf\n", m_aver);
                    printf("Number of passed students: %d\n", m_passed);
                    printf("Number of failed students: %d\n\n", cur_stu_num - m_passed);

                    printf("English\n");
                    printf("Average Score: %.2lf\n", e_aver);
                    printf("Number of passed students: %d\n", e_passed);
                    printf("Number of failed students: %d\n\n", cur_stu_num - e_passed);

                    printf("Programming\n");
                    printf("Average Score: %.2lf\n", p_aver);
                    printf("Number of passed students: %d\n", p_passed);
                    printf("Number of failed students: %d\n\n", cur_stu_num - p_passed);

                    printf("Overall:\n");
                    printf("Number of students who passed all subjects: %d\n", all_passed);
                    printf("Number of students who passed 3 or more subjects: %d\n", three_passed);
                    printf("Number of students who passed 2 or more subjects: %d\n", two_passed);
                    printf("Number of students who passed 1 or more subjects: %d\n", one_passed);
                    printf("Number of students who failed all subjects: %d\n", all_failed);
                }
            }
        }
    }
    return 0;
}
