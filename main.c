#include <stdio.h>
#include <stdlib.h>
#include "cherish.h"

void displayMenu() {
    printf("********** 链表操作菜单 **********\n");
    printf("1. 初始化链表\n");
    printf("2. 插入元素\n");
    printf("3. 遍历链表\n");
    printf("4. 获取链表长度\n");
    printf("5. 判断链表是否为空\n");
    printf("6. 查找元素\n");
    printf("7. 获取指定位置的元素\n");
    printf("8. 删除元素\n");
    printf("9. 逆序输出链表\n");
    printf("10. 销毁链表\n");
    printf("0. 退出\n");
    printf("*********************************\n");
    printf("请输入菜单选项：");
}

int main() {
    LinkList list = NULL;
    int choice, pos, item;
    DataType data;

    while (1) {
        displayMenu();
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            // 初始化链表
            if (!InitList(&list)) {
                printf("初始化链表失败！\n");
            }
            else {
                printf("链表初始化成功！\n");
            }
            break;

        case 2:
            // 插入元素
            printf("请输入要插入的元素位置和数值（用空格分隔）：");
            scanf_s("%d %d", &pos, &item);
            if (ListInsert(list, pos, item)) {
                printf("插入元素成功！\n");
            }
            else {
                printf("插入元素失败！\n");
            }
            break;

        case 3:
            // 遍历链表
            printf("链表元素：");
            TraverseList(list);
            break;

        case 4:
            // 获取链表长度
            printf("链表长度：%d\n", ListLength(list));
            break;

        case 5:
            // 判断链表是否为空
            if (ListEmpty(list)) {
                printf("链表为空！\n");
            }
            else {
                printf("链表不为空！\n");
            }
            break;

        case 6:
            // 查找元素
            printf("请输入要查找的元素数值：");
            scanf_s("%d", &data);
            PNode node = Find(list, data);
            if (node) {
                printf("找到元素：%d\n", node->data);
            }
            else {
                printf("未找到元素！\n");
            }
            break;

        case 7:
            // 获取指定位置的元素
            printf("请输入要获取元素的位置：");
            scanf_s("%d", &pos);
            if (GetElem(list, pos, &data)) {
                printf("指定位置的元素：%d\n", data);
            }
            else {
                printf("获取元素失败！\n");
            }
            break;

        case 8:
            // 删除元素
            printf("请输入要删除的元素位置：");
            scanf_s("%d", &pos);
            if (ListDelete(list, pos, &item)) {
                printf("删除的元素：%d\n", item);
            }
            else {
                printf("删除元素失败！\n");
            }
            break;

        case 9:
            // 逆序输出链表
            printf("逆序输出链表：");
            out(list);
            printf("\n");
            break;

        case 10:
            // 销毁链表
            DestroyList(list);
            printf("链表已销毁！\n");
            break;

        case 0:
            // 退出程序
            printf("程序已退出！\n");
            exit(0);

        default:
            printf("无效的菜单选项！\n");
            break;
        }

        printf("\n");
    }

    return 0;
}
