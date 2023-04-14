// Các thu vien can thiet cho chuong trình
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define sl 100


struct Date
{
    int ngay;
    int thang;
    int nam;
};
typedef struct Date date;

struct NhanVien
{
    int manv;
    char ho[30];
    char ten[30];
    date namsinh;
    char noisinh[100];
    char diachi[200];
    float luong;
    date ngayvao;
};
typedef struct NhanVien nhanvien;

struct DanhSach
{
    nhanvien a[sl];
    int n;
};
typedef struct DanhSach danhsach;

void nhapngaythang(date &ntn)
{
    do
    {
        printf("\n\tNhap vao ngay:");
        scanf("%d", &ntn.ngay);
    } while (ntn.ngay < 0 || ntn.ngay > 31);
    do
    {
        printf("\tNhap vao thang:");
        scanf("%d", &ntn.thang);
    } while (ntn.thang < 0 || ntn.thang > 12);
    printf("\tNhap vao nam:");
    scanf("%d", &ntn.nam);
}
void nhap1nv(nhanvien &nv)
{
    printf("\tNhap vao msnv:");
    scanf("%d", &nv.manv);
    printf("\tNhap vao ho:");
    fflush(stdin);
    gets(nv.ho);
    printf("\tNhap vao ten:");
    fflush(stdin);
    gets(nv.ten);
    printf("\tNhap vao ngay thang nam sinh nhan vien:");
    nhapngaythang(nv.namsinh);
    printf("\tNhap vao noi sinh:");
    fflush(stdin);
    gets(nv.noisinh);
    printf("\tNhap vao dia chi:");
    fflush(stdin);
    gets(nv.diachi);
    printf("\tNhap vao luong:");
    scanf("%f", &nv.luong);
    printf("\tNhap vao ngay vao:");
    nhapngaythang(nv.ngayvao);
}
void xuatngaythang(date ntn)
{
    printf("\n\t%d-%d-%d", ntn.ngay, ntn.thang, ntn.nam);
}
void xuat1nv(nhanvien nv)
{
	printf("\n\tThong tinh nhan vien!");
    printf("\n\tMa so nhan vien:%d", nv.manv);
    printf("\n\tHo:%s", nv.ho);
    printf("\n\tTen:%s", nv.ten);
    printf("\n\tNgay thang nam sinh nhan vien:");
    xuatngaythang(nv.namsinh);
    printf("\n\tNoi sinh:%s", nv.noisinh);
    printf("\n\tDia chi:%s", nv.diachi);
    printf("\n\tLuong:%f", nv.luong);
    printf("\n\tNgay vao:");
    xuatngaythang(nv.ngayvao);
}

void nhapdanhsach(danhsach &ds)
{
    do{
    	printf("\tNhap so luong nhan vien:");
    	scanf("%d", &ds.n);
	}while(ds.n<=0);
    printf("\tMoi nhap thong tinh nhan vien!");
    for (int i = 0; i < ds.n; i++)
    {
        printf("\n\tNhan vien thu %d\n", i + 1);
        nhap1nv(ds.a[i]);
        printf("================================================================\n");
    }
}
void xuatdanhsach(danhsach ds)
{
    printf("\tDanh sach nhan vien:\n");
    for (int i = 0; i < ds.n; i++)
    {
        printf("\tNhan vien thu %d", i + 1);
        xuat1nv(ds.a[i]);
        printf("\n================================================================\n");
    }
}

void timten(danhsach ds, char *c){
	int i;
	int dem=0;
 	for (int i = 0; i < ds.n; i++){
 		if(strcmp(strlwr(ds.a[i].ten),strlwr(c))==0){
 			printf("\n\tDa tim thay nhan vien o vi tri:%d",i+1);
 			xuat1nv(ds.a[i]);
 			dem++;
 		}
	} 
	if(dem==0){
		printf("\n\tKhong tim thay nhan vien");
	}
}
void themnv(danhsach &ds, nhanvien nv, int k)
{
    for (int i = ds.n; i > k; i--)
    {
        ds.a[i] = ds.a[i - 1];
    }
    ds.a[k] = nv;
    ds.n++;
}
int timMSNV(danhsach ds, int d){
	int i;
	for(i=0;i<ds.n;i++){
		if(ds.a[i].manv==d){
			return i;
			break;
		}
	}
	return -1;
}
void sapxep(danhsach &ds){
	  int i, j;
    for (i = 0; i < ds.n - 1; i++) {
        for (j = i + 1; j < ds.n; j++) {
            if (ds.a[i].luong < ds.a[j].luong) {
                nhanvien temp = ds.a[i];
                ds.a[i] = ds.a[j];
                ds.a[j] = temp;
            }
        }
    }	
}
void xoanv(danhsach *ds, int d){
	int vtri = timMSNV(*ds,d);
	int i;
	if(vtri==-1){
		printf("\n\tKhong tim thay nhan vien de xoa");
	}else{
		for(i=vtri;i<ds->n-1;i++){
			ds->a[i] = ds->a[i+1];
		}
		printf("\n\tDa xoa nhan vien tai vi tri:%d",vtri+1);
		ds->n--;
	}
}

void menu()
{
    int chon;
    int d, k;
    danhsach ds;
    nhanvien nv;
    nhapdanhsach(ds);
    xuatdanhsach(ds);
    do
    {
        printf("\n\t-------------------------MENU-----------------------");
        printf("\n\t 1.Them vao 1 nhan vien");
        printf("\n\t 2.Tim nhan vien theo ma so");
        printf("\n\t 3.Tim nhan vien theo ten");
        printf("\n\t 4.Bang luong nhan vien giam dan");
        printf("\n\t 5.Xoa 1 nhan vien");
        printf("\n\t 0.Thoat");
        printf("\n\t----------------------------------------------------");
        printf("\n\tMoi ban chon:");
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
            printf("\n\t 1.Them vao 1 nhan vien");
            printf("\n\t--------------------------------");
            printf("\n\t Ban them o vi tri:");
            scanf("%d", &k);
            nhap1nv(nv);
            themnv(ds, nv, k);
            printf("\n\tDanh sach sau khi them:");
            xuatdanhsach(ds);
            break;
        case 2:
            printf("\n\t 2.Tim nhan vien theo ma so");
            printf("\n\t--------------------------------");
            printf("\n\t Moi nhap ma so nhan vien can tim:");
            scanf("%d",&d);
            if(timMSNV(ds,d)!=-1){
            	printf("\n\tDa tim thay nhan vien o vi tri:%d",timMSNV(ds,d)+1);
            	xuat1nv(ds.a[timMSNV(ds,d)]);
			}else{
				printf("\n\tKhong tim thay nhan vien");
			}
            break;
        case 3:
            printf("\n\t 3.Tim nhan vien theo ten");
            char c[30];
            printf("\n\t Moi nhap ten nhan vien can tim:");
            fflush(stdin);
    		gets(c);
    		timten(ds,c);
            break;
        case 4:
            printf("\n\t 4.Bang luong nhan vien giam dan\n");
            sapxep(ds);
            xuatdanhsach(ds);
            break;
        case 5:
            printf("\n\t 5.Xoa 1 nhan vien");
            printf("\n\t--------------------------------");
            printf("\n\t Moi nhap ma so nhan vien can xoa:");
            scanf("%d",&d);
            xoanv(&ds,d);
        	printf("\n\tDanh sach nhan vien sau khi xoa!\n");
            xuatdanhsach(ds);
            break;
        case 0:
            printf("\n\t Ban chon thoat");
            exit(0);
            break;

        default:
            printf("\n\t Khong tim thay chuc nang moi ban nhap lai");
            break;
        }
    } while (1);
}

// =================================
int main()
{
    menu();
//	getch();//doc 1 ky tu tu ban phim khong can an enter
    return 0;
}
// =================================
