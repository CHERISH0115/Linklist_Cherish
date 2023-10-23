#include <stdio.h>
#include <stdlib.h>
#include "cherish.h"

void displayMenu() {
    printf("********** ��������˵� **********\n");
    printf("1. ��ʼ������\n");
    printf("2. ����Ԫ��\n");
    printf("3. ��������\n");
    printf("4. ��ȡ������\n");
    printf("5. �ж������Ƿ�Ϊ��\n");
    printf("6. ����Ԫ��\n");
    printf("7. ��ȡָ��λ�õ�Ԫ��\n");
    printf("8. ɾ��Ԫ��\n");
    printf("9. �����������\n");
    printf("10. ��������\n");
    printf("0. �˳�\n");
    printf("*********************************\n");
    printf("������˵�ѡ�");
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
            // ��ʼ������
            if (!InitList(&list)) {
                printf("��ʼ������ʧ�ܣ�\n");
            }
            else {
                printf("�����ʼ���ɹ���\n");
            }
            break;

        case 2:
            // ����Ԫ��
            printf("������Ҫ�����Ԫ��λ�ú���ֵ���ÿո�ָ�����");
            scanf_s("%d %d", &pos, &item);
            if (ListInsert(list, pos, item)) {
                printf("����Ԫ�سɹ���\n");
            }
            else {
                printf("����Ԫ��ʧ�ܣ�\n");
            }
            break;

        case 3:
            // ��������
            printf("����Ԫ�أ�");
            TraverseList(list);
            break;

        case 4:
            // ��ȡ������
            printf("�����ȣ�%d\n", ListLength(list));
            break;

        case 5:
            // �ж������Ƿ�Ϊ��
            if (ListEmpty(list)) {
                printf("����Ϊ�գ�\n");
            }
            else {
                printf("����Ϊ�գ�\n");
            }
            break;

        case 6:
            // ����Ԫ��
            printf("������Ҫ���ҵ�Ԫ����ֵ��");
            scanf_s("%d", &data);
            PNode node = Find(list, data);
            if (node) {
                printf("�ҵ�Ԫ�أ�%d\n", node->data);
            }
            else {
                printf("δ�ҵ�Ԫ�أ�\n");
            }
            break;

        case 7:
            // ��ȡָ��λ�õ�Ԫ��
            printf("������Ҫ��ȡԪ�ص�λ�ã�");
            scanf_s("%d", &pos);
            if (GetElem(list, pos, &data)) {
                printf("ָ��λ�õ�Ԫ�أ�%d\n", data);
            }
            else {
                printf("��ȡԪ��ʧ�ܣ�\n");
            }
            break;

        case 8:
            // ɾ��Ԫ��
            printf("������Ҫɾ����Ԫ��λ�ã�");
            scanf_s("%d", &pos);
            if (ListDelete(list, pos, &item)) {
                printf("ɾ����Ԫ�أ�%d\n", item);
            }
            else {
                printf("ɾ��Ԫ��ʧ�ܣ�\n");
            }
            break;

        case 9:
            // �����������
            printf("�����������");
            out(list);
            printf("\n");
            break;

        case 10:
            // ��������
            DestroyList(list);
            printf("���������٣�\n");
            break;

        case 0:
            // �˳�����
            printf("�������˳���\n");
            exit(0);

        default:
            printf("��Ч�Ĳ˵�ѡ�\n");
            break;
        }

        printf("\n");
    }

    return 0;
}
