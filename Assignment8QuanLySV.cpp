#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
// HAM LE
void createBorder(int len, int border);
void borderRectangle(int borderLeft, int len, int border, int borderRight);
//-----------------------------------------------------------------------------------
void printEmptyList();
void nhapSV(struct SinhVien ds[], int n);
char *hocLuc(double diem);
void xuatSV(struct SinhVien ds[], int n);
void sapXepGiamDan(struct SinhVien ds[], int n);
void themSV(struct SinhVien ds[], int n);
void xoaSV(struct SinhVien ds[], int n);
void timSVCoDiemCaoNhatVaThapNhap(struct SinhVien ds[], int n);
void timSVTheoTen(struct SinhVien ds[], int n);
void timSVTheoTenNangCao(struct SinhVien ds[], int n); // Chi can nhap cac ky tu co lien quan toi ten SV
void suaDiemSinhVien(struct SinhVien ds[], int n);
void hienThiBieuDo(struct SinhVien ds[], int n);
void quanLySinhVien();
////////// BAI 8: HIEN THI THONG TIN SINH VIEN ////////////
struct SinhVien{
	char tenSV[50];
	double diem;
};
int main(){
	quanLySinhVien();
}
void quanLySinhVien(){
	int choice;
	int n=0;
	struct SinhVien ds[50];
	do{
		system("cls");
		printf("\n\t%c",218);
		createBorder(56,196);
		printf("%c",191);
		printf("\n\t%c\t        QUAN LY SINH VIEN%25c\n",179,179);
		printf("\t%c  1.  Nhap sinh vien%37c\n",179,179);
		printf("\t%c  2.  Xuat danh sach sinh vien%27c\n",179,179);
		printf("\t%c  3.  Sap xep sinh vien giam dan%25c\n",179,179);
		printf("\t%c  4.  Them sinh vien%37c\n",179,179);
		printf("\t%c  5.  Xoa sinh vien%38c\n",179,179);
		printf("\t%c  6.  Hien thi sinh vien co diem cao nhat va thap nhat%3c\n",179,179);
		printf("\t%c  7.  Tim sinh vien theo ten%29c\n",179,179);
		printf("\t%c  8.  Tim sinh vien nang cao%29c\n",179,179);
		printf("\t%c  9.  Sua diem sinh vien%33c\n",179,179);
		printf("\t%c  10. Hien thi bieu do%35c\n",179,179);
		printf("\t%c  0.  Thoat chuong trinh%33c\n",179,179);
		printf("\t%c",192);
		createBorder(56,196);
		printf("%c",217);
		printf("\n\n\tNhap chuc nang: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\n\tNhap so luong sinh vien: ");
				scanf("%d",&n);
				nhapSV(ds,n);
				break;
			case 2:
				if(n==0){
					printEmptyList();
				}else{
					xuatSV(ds,n);
				}
				break;
			case 3:
				if(n==0){
					printEmptyList();
				}else{
					sapXepGiamDan(ds,n);
					printf("\n\tSAP XEP THANH CONG, CHON 2 DE XUAT DANH SACH!\n\n");
				}
				break;
			case 4:
				themSV(ds,n);
				n++;
				break;
			case 5:
				if(n==0){
					printf("\n\tKHONG CO SINH VIEN DE XOA\n\n");
				}else{
					xoaSV(ds,n);
					n--;
				}
				break;
			case 6:
				if(n==0){
					printEmptyList();
				}else{
					timSVCoDiemCaoNhatVaThapNhap(ds,n);
				}	
				break;
			case 7:
				if(n==0){
					printEmptyList();
				}else{
					timSVTheoTen(ds,n);
				}
				break;
			case 8:
				if(n==0){
					printEmptyList();
				}else{
					timSVTheoTenNangCao(ds,n);
				}	
				break;
			case 9:
				if(n==0){
					printEmptyList();
				}else{
					suaDiemSinhVien(ds,n);
				}			
				break;
			case 10:
				if(n==0){
					printEmptyList();
				}else{
					hienThiBieuDo(ds,n);
				}			
				break;
			case 0:
				printf("\n\tChuong trinh ket thuc!\n\n");
				return;
				break;
			default:
				printf("\n\tGia tri khong hop le, vui long nhap lai!\n\n");
		}
		
		printf("\n\tNhan ENTER de chon chuc nang khac...");
		getch();
	}while(true);
}
void nhapSV(struct SinhVien ds[], int n){
	for(int i=0; i<n; i++){
		fflush(stdin);
		printf("\n");
		printf("\tSinh vien %d:\n",i+1);
		printf("\tTen: ");
		gets(ds[i].tenSV);
		printf("\tDiem: ");
		scanf("%lf",&ds[i].diem);
	}
	printf("\n\t\tNHAP HOAN TAT, CHON 2 DE XUAT DANH SACH!\n");
}
char *hocLuc(double diem){
	char *kq;
	if(diem>=9){
		kq = "Xuat Sac";
	}else if(diem>=8){
		kq = "Gioi";
	}else if(diem>=6.5){
		kq = "Kha";
	}else if(diem>=5){
		kq = "Trung Binh";
	}else{
		kq = "Yeu";
	}
}

void xuatSV(struct SinhVien ds[], int n){
	printf("\n\t\t\t\tDANH SACH SINH VIEN\n\n\n");
	printf("\tSTT\t%c\tHO VA TEN\t%c\tDIEM\t%c\tHOC LUC\n",179,179,179,179);
	printf("\t\t%c\t\t\t%c\t\t%c\n",179,179,179,179);
	for(int i=0; i<n; i++){
		printf("\t%02d\t%c\t%s\t\t%c\t%.1lf\t%c\t%s\n",i+1,179,ds[i].tenSV,179,ds[i].diem,179,hocLuc(ds[i].diem));
		printf("\t\t%c\t\t\t%c\t\t%c\n",179,179,179,179);
	}
	printf("\n");
}

void sapXepGiamDan(struct SinhVien ds[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(ds[i].diem < ds[j].diem){
				struct SinhVien temp;
				temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}

void themSV(struct SinhVien ds[], int n){
	fflush(stdin);
	printf("\n\tSinh vien %d:\n",n+1);
	printf("\tTen: ");
	gets(ds[n].tenSV);
	printf("\tDiem: ");
	scanf("%lf",&ds[n].diem);
	printf("\n\tTHEM SINH VIEN THANH CONG, CHON 2 DE XUAT DANH SACH!\n\n");
}

void xoaSV(struct SinhVien ds[], int n){
	xuatSV(ds,n);
	int pos;
	printf("\n\tNhap vi tri can xoa: ");
	scanf("%d",&pos);
	printf("\n\tXOA THANH CONG SINH VIEN TEN %s, CHON 2 DE XUAT LAI DANH SACH!\n\n",strupr(ds[pos-1].tenSV));
	for(int i=pos-1; i<n-1; i++){
		ds[i] = ds[i+1];
	}
}

void timSVCoDiemCaoNhatVaThapNhap(struct SinhVien ds[], int n){
	sapXepGiamDan(ds,n);
	printf("\n\tSinh vien co diem cao nhat:\n\n");
	double max = ds[0].diem;
	for(int i=0; i<n; i++){
		if(max == ds[i].diem){
			printf("\t\t%02d\tTen: %s\t\tDiem: %.1lf\n\n",i+1,ds[i].tenSV,ds[i].diem);
		}
	}
	printf("\tSinh vien co diem thap nhat:\n\n");
	double min = ds[n-1].diem;
	int dem=0;
	for(int i=n-1; i>0; i--){
		if(min == ds[i].diem){
			dem++;
			printf("\t\t%02d\tTen: %s\t\tDiem: %.1lf\n\n",dem,ds[i].tenSV,ds[i].diem);
		}
	}
}

void timSVTheoTen(struct SinhVien ds[], int n){
	char name[30];
	struct SinhVien dsMoi[30];
	int k=0;
	fflush(stdin);
	printf("\n\tNhap ten sinh vien muon tim: ");
	gets(name);
	strlwr(name);
	int flag = -1;
	for(int i=0; i<n; i++){
		if(strcmp(strlwr(ds[i].tenSV),name)==0){
			dsMoi[k] = ds[i];
			k++;
			flag = 1;
		}
	}
	if(flag == -1){
		printf("\n\tKHONG TIM THAY TEN SINH VIEN TRONG DANH SACH!\n\n");
	}else{
		printf("\n\tKET QUA: \n");
		xuatSV(dsMoi,k);
	}
}

void timSVTheoTenNangCao(struct SinhVien ds[], int n){
	struct SinhVien dsMoi[30];
	int k=0;
	char name[50];
	fflush(stdin);
	printf("\n\tNhap cac ky tu muon tim: ");
	gets(name);
	strlwr(name); // DUNG STRLWR CHO 2 CHUOI DE TOI UU VIEC TIM KIEM
	int flag=0;
	for(int i=0; i<n; i++){
		if(strstr(strlwr(ds[i].tenSV),name)!=NULL){
			dsMoi[k] = ds[i];
			k++;
			flag=1;
		}
	}
	if(flag == 0){
		printf("\n\tKHONG TIM THAY KY TU PHU HOP TRONG DANH SACH!\n\n");
	}else{
		printf("\n\tCAC KET QUA TIM DUOC: \n");
		xuatSV(dsMoi,k);
	}
}

void suaDiemSinhVien(struct SinhVien ds[], int n){
	int pos;
	xuatSV(ds,n);
	printf("\n\tNhap vi tri sinh vien muon sua diem: ");
	scanf("%d",&pos);
	fflush(stdin);
	
	if(pos<1||pos>n){
		printf("\n\tKhong tim thay vi tri nay.\n\n");
	}else{
		printf("\n\tNhap diem moi: ");
		scanf("%lf",&ds[pos-1].diem);
		printf("\n\tSUA DIEM THANH CONG CHO SINH VIEN TEN %s, ",strupr(ds[pos-1].tenSV));
		printf("CHON 2 DE XUAT LAI DANH SACH!\n\n");
		fflush(stdin);
	}
}

void hienThiBieuDo(struct SinhVien ds[], int n){
	printf("\n\tHIEN THI BIEU DO\n\n\n");
	for(int i=0; i<n; i++){
		printf("\t  %.2lf   ",ds[i].diem);
		for(float j=0; j<ds[i].diem*3; j++){
			printf("%c",178);
		}
		printf("  %s\n\n",strupr(ds[i].tenSV));
		
		printf("\n");	
	}
}
////////// HET BAI 8 ////////////

//-----------------------------------------------------------------------------------


void createBorder(int len, int border){
	for(int i=0; i<len; i++) {
	    printf("%c",border);
	}
}
void borderRectangle(int borderLeft, int len, int border, int borderRight){
	printf("\t\t%c",borderLeft);
	createBorder(len,border);
	printf("%c",borderRight);
}

void printEmptyList(){
	printf("\n\tDanh sach sinh vien trong, vui long nhap sinh vien!\n");
}
