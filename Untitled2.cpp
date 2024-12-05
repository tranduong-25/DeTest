#include <stdio.h>

int kiemTraSoHoanHao(int n) {
    int tong = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            tong += i;
        }
    }
    return (tong == n);
}

int timGiaTriNhoThuHai(int mang[], int soPhanTu) {
    int nhoNhat = mang[0], nhoThuHai = -1;
    for (int i = 1; i < soPhanTu; i++) {
        if (mang[i] < nhoNhat) {
            nhoThuHai = nhoNhat;
            nhoNhat = mang[i];
        } else if (mang[i] > nhoNhat && (nhoThuHai == -1 || mang[i] < nhoThuHai)) {
            nhoThuHai = mang[i];
        }
    }
    return nhoThuHai;
}

int timKiemTuyenTinh(int mang[], int soPhanTu, int giaTri) {
    for (int i = 0; i < soPhanTu; i++) {
        if (mang[i] == giaTri) {
            return 1; 
        }
    }
    return 0; 
}

int sapXepBubble(int mang[], int soPhanTu) {
    for (int i = 0; i < soPhanTu - 1; i++) {
        for (int j = 0; j < soPhanTu - i - 1; j++) {
            if (mang[j] > mang[j + 1]) {
                int tam = mang[j];
                mang[j] = mang[j + 1];
                mang[j + 1] = tam;
            }
        }
    }
    return 0;
}

int sapXepLeChan(int mang[], int soPhanTu) {
    int i = 0, j = soPhanTu - 1;
    while (i < j) {
        if (mang[i] % 2 == 0 && mang[j] % 2 != 0) {
            int tam = mang[i];
            mang[i] = mang[j];
            mang[j] = tam;
        }
        if (mang[i] % 2 != 0) i++;
        if (mang[j] % 2 == 0) j--;
    }
    return 0;
}

int kiemTraMangTangDan(int mang[], int soPhanTu) {
    for (int i = 0; i < soPhanTu - 1; i++) {
        if (mang[i] > mang[i + 1]) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int mang[100];
    int soPhanTu, luaChon, giaTri, viTri;

    do {
        printf("MENU:\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong cac so hoan hao\n");
        printf("4. Tim gia tri nho thu 2\n");
        printf("5. Them phan tu vao mang\n");
        printf("6. Xoa phan tu tai mot vi tri\n");
        printf("7. Sap xep mang theo thu tu tang dan (Bubble sort)\n");
        printf("8. Tim kiem phan tu trong mang\n");
        printf("9. Sap xep mang: so le truoc so chan\n");
        printf("10. Kiem tra mang co phai mang tang dan\n");
        printf("11. Thoat\n");
        printf("Chon chuc nang (1-11): ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &soPhanTu);
                printf("Nhap gia tri cac phan tu:\n");
                for (int i = 0; i < soPhanTu; i++) {
                    scanf("%d", &mang[i]);
                }
                break;

            case 2:
                printf("Cac phan tu trong mang:\n");
                for (int i = 0; i < soPhanTu; i++) {
                    printf("mang[%d] = %d\n", i, mang[i]);
                }
                break;

            case 3:
                {
                    int dem = 0;
                    for (int i = 0; i < soPhanTu; i++) {
                        if (kiemTraSoHoanHao(mang[i])) {
                            dem++;
                        }
                    }
                    printf("So luong so hoan hao trong mang: %d\n", dem);
                }
                break;

            case 4:
                {
                    int nhoThuHai = timGiaTriNhoThuHai(mang, soPhanTu);
                    if (nhoThuHai == -1) {
                        printf("Khong tim thay gia tri nho thu 2\n");
                    } else {
                        printf("Gia tri nho thu 2 la: %d\n", nhoThuHai);
                    }
                }
                break;

            case 5:
                printf("Nhap gia tri phan tu can them: ");
                scanf("%d", &giaTri);
                printf("Nhap vi tri them: ");
                scanf("%d", &viTri);
                if (viTri >= 0 && viTri < soPhanTu) {
                    int daTonTai = 0;
                    for (int i = 0; i < soPhanTu; i++) {
                        if (mang[i] == giaTri) {
                            daTonTai = 1;
                            break;
                        }
                    }
                    if (!daTonTai) {
                        for (int i = soPhanTu; i > viTri; i--) {
                            mang[i] = mang[i - 1];
                        }
                        mang[viTri] = giaTri;
                        soPhanTu++;
                        printf("Da them phan tu %d vao vi tri %d\n", giaTri, viTri);
                    } else {
                        printf("Phan tu da ton tai trong mang\n");
                    }
                } else {
                    printf("Vi tri khong hop le\n");
                }
                break;

            case 6:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &viTri);
                if (viTri >= 0 && viTri < soPhanTu) {
                    for (int i = viTri; i < soPhanTu - 1; i++) {
                        mang[i] = mang[i + 1];
                    }
                    soPhanTu--;
                    printf("Da xoa phan tu tai vi tri %d\n", viTri);
                } else {
                    printf("Vi tri khong hop le\n");
                }
                break;

            case 7:
                sapXepBubble(mang, soPhanTu);
                printf("Mang sau khi sap xep:\n");
                for (int i = 0; i < soPhanTu; i++) {
                    printf("%d ", mang[i]);
                }
                printf("\n");
                break;

            case 8:
                printf("Nhap phan tu can tim: ");
                scanf("%d", &giaTri);
                if (timKiemTuyenTinh(mang, soPhanTu, giaTri)) {
                    printf("Phan tu %d co trong mang\n", giaTri);
                } else {
                    printf("Phan tu %d khong co trong mang\n", giaTri);
                }
                break;

            case 9:
                sapXepLeChan(mang, soPhanTu);
                printf("Mang sau khi sap xep so le truoc so chan:\n");
                for (int i = 0; i < soPhanTu; i++) {
                    printf("%d ", mang[i]);
                }
                printf("\n");
                break;

            case 10:
                if (kiemTraMangTangDan(mang, soPhanTu)) {
                    printf("Mang la mang tang dan\n");
                } else {
                    printf("Mang khong phai la mang tang dan\n");
                }
                break;

            case 11:
                printf("Thoat khoi chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long chon lai.\n");
        }
    } while (luaChon != 11);

    return 0;
}

