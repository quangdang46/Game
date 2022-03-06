import array as arr 
import random
import math
import os

def kiemtracuphap(a,ChuoiCuPhap,GoiYCuPhap):
	temp=0
	for i in range(0,len(ChuoiCuPhap)):
		if a==ChuoiCuPhap[i]:
			temp=1
			b=a
			return b
			break
	if temp==0:
		print("Bạn đã nhập sai cú pháp "+ GoiYCuPhap+". Mời bạn nhập lại: ",end="")
		c=input()
		d=kiemtracuphap(c,ChuoiCuPhap,GoiYCuPhap)
		return d

def kiemtraso(a):
	if str(a).isdigit():
		temp=a
		return temp
	else:
		print("Bạn đã nhập sai cú pháp. Mời bạn nhập lại: ",end="")
		b=input()
		c=kiemtraso(b)
		return c

def DeckCheck(x):
	if x==0:
		return str(0)
	else:
		a = x%13
		b = x//14
		if a==1:
			a="A"
		elif a==11:
			a="J"
		elif a==12:
			a="Q"
		elif a==0:
			a="K"
		if b==0:
			c="Bích"
		elif b==1:
			c="Chuồn"
		elif b==2:
			c="Rô"
		elif b==3:
			c="Cơ"
		return str(a)+" "+c

def DeckDistribute(Deck):
	tempcard=random.randint(1,52)
	while Deck[tempcard]==0:
		tempcard=random.randint(1,52)
	Deck[tempcard]=0
	return tempcard

def CardPoints(a):
	if a==0:
		return 0
	elif DeckCheck(a)[0:1]=="K" or DeckCheck(a)[0:1]=="J" or DeckCheck(a)[0:1]=="Q":
		return 10
	else:
		return int(a%13)

def TakeCards(c,D,C2):
	for m in range((c-1)*5,5+(c-1)*5):
		if C2[m]==0:
			C2[m]= DeckDistribute(D)
			break
		else:
			pass

def SumCardPoints(b,E):
	DemA=0
	global numofcom
	SumCardPoints=[0 for i in range(1,numofcom+5)]
	for j in range((b-1)*5,5+(b-1)*5):
		if DeckCheck(E[j])[0:1]!="A":
			temp0=CardPoints(E[j])
			SumCardPoints[b]=SumCardPoints[b]+temp0
		else:
			DemA=DemA+1
	temp1=SumCardPoints[b]
	tempArray=[1 for i in range(DemA+5)]
	for k in range(0,DemA+1):
		tempArray[k]=temp1+10*k+1*(DemA-k)
		a=tempArray[k]
		if a<21 and k>0:
			if (a+k)<=21:
				a=a+k
			elif (a+k)>21:
				a=21
		tempArray[k]=a
		if tempArray[k]>21:
			tempArray[k]=0
	temp2=max(tempArray)
	#if temp2>21:
		#temp2=0
	#if temp2<21 and temp2>0:
		#if (temp2+DemA)<=21:
			#temp2=temp2+DemA
		#elif (temp2+DemA)>21:
			#temp2=21
	if temp2==1:
		temp2=0
	return temp2

def DemXi(d,F):
	tempdemxi=0
	for l in range((d-1)*5,5+(d-1)*5):
		q=DeckCheck(F[l])[0:1]
		if q=="A":
			tempdemxi=tempdemxi+1
	return tempdemxi

def SoBaiNhaCaiVoiMay(a):
	tempsobai1=SumCardPoints(1,ListNhaCai)
	tempsobai2=SumCardPoints(a,ListMay)
	if tempsobai1>tempsobai2:
		print("Người chơi "+TenMay[a]+" đã thua nhà cái")
		Camthanthua(a,ListMay)
	elif tempsobai1==tempsobai2:
		print("Người chơi "+TenMay[a]+" đã huề nhà cái")
	elif tempsobai1<tempsobai2: 
		print("Người chơi "+TenMay[a]+" đã thắng nhà cái")
		Camthanthang(a,ListMay)

def SoBaiNhaCaiVoiNguoiChoi():
	tempsobai1=SumCardPoints(1,ListNhaCai)
	tempsobai2=SumCardPoints(1,ListNguoiChoi)
	if tempsobai2<16:
		print("Bạn "+TenNguoiChoi+" sao chưa đủ tuổi mà không rút tiếp???")
		tempsobai2=0
	if tempsobai1>tempsobai2:
		print("Người chơi "+TenNguoiChoi+" đã thua nhà cái")
		Thuatien()
	elif tempsobai1==tempsobai2:
		print("Người chơi "+TenNguoiChoi+" đã huề nhà cái")
	else: 
		print("Người chơi "+TenNguoiChoi+" đã thắng nhà cái")
		Thangtien()

def LenBai(z,G):
	print("")
	print("Lên bài: ",end="")
	for i in range((z-1)*5,5+(z-1)*5):
		if G[i]>0:
			print(DeckCheck(G[i]),end=" | ")
	print("\n")

def NhaCaiXiBan():
	temp=0
	if DemXi(1,ListNhaCai)==2:
		temp=1
		LenBai(1,ListNhaCai)
		print("Nhà cái xì bàn. Lật bài lên hết!")
		for i in range(1,numofcom+1):
			print("Bài của "+TenMay[i]+" là: ")
			LenBai(i,ListMay)
			if DemXi(i,ListMay)==2:
				print("Người chơi "+TenMay[i]+" đã huề nhà cái")
			else:
				print("Người chơi "+TenMay[i]+" đã thua nhà cái")
		LenBai(1,ListNguoiChoi)
		if DemXi(1,ListNguoiChoi)==2:
			print("Người chơi "+TenNguoiChoi+" đã huề nhà cái")
		else:
			print("Người chơi "+TenNguoiChoi+" đã thua nhà cái")
			Thuatien()
	else:
		pass
	return temp

def CheckXiBanNhaCai():
	if DemXi(1,ListNhaCai)==2:
		LenBai(1,ListNhaCai)
		return 1
	else:
		return 0 

def CheckXiBanMay(g,H):
	temp=0
	if DemXi(g,H)==2:
		print("Người chơi "+TenMay[g]+" xì bàn")
		LenBai(g,H)
		temp=1
		if CheckXiBanNhaCai()==1:
			print("Người chơi "+TenMay[g]+" đã huề nhà cái")
		else:
			print("Người chơi "+TenMay[g]+" đã thắng nhà cái")
		print(5*"...")
	return temp

def CheckXiBanNguoiChoi():
	temp=0
	if DemXi(1,ListNguoiChoi)==2:
		print("Người chơi "+TenNguoiChoi+" xì bàn")
		LenBai(1,ListNguoiChoi)
		temp=1
		if CheckXiBanNhaCai()==1:
			print("Người chơi "+TenNguoiChoi+" đã huề nhà cái")
		else:
			print("Người chơi "+TenNguoiChoi+" đã thắng nhà cái")
			Thangtien()
		print(5*"...")
	return temp

def CheckXiDachMay(a,C):
	temp=0
	tempxidach=SumCardPoints(a,C)
	if tempxidach==21:
		temp=1
		print("Người chơi "+TenMay[a]+" xì dách")
		LenBai(a,C)
		SoBaiNhaCaiVoiMay(a)
		print(5*"...")
	else:
		pass
	return temp

def CheckXiDachNguoiChoi():
	temp=0
	tempxidach=SumCardPoints(1,ListNguoiChoi)
	if tempxidach==21:
		temp=1
		print("Người chơi "+TenNguoiChoi+" xì dách")
		LenBai(1,ListNguoiChoi)
		SoBaiNhaCaiVoiNguoiChoi()
		print(5*"...")
	else:
		pass
	return temp

def Mayrutbai(a,B):
	temprutbai=SumCardPoints(a,B)
	coruthaykhong=0
	if temprutbai>=20 or temprutbai==0:
		print(TenMay[a]+" : Tôi không rút nữa!")
		pass
	elif temprutbai==19:
		ngaunhien=random.randint(1,100)
		if ngaunhien<=5:
			print(TenMay[a]+" : Tôi rút tiếp!")
			TakeCards(a,BoBai,B)
			coruthaykhong=1
			pass
		else:
			print(TenMay[a]+" : Tôi không rút nữa!")
			pass
	elif temprutbai==18:
		ngaunhien=random.randint(1,100)
		if ngaunhien<=50:
			print(TenMay[a]+" : Tôi rút tiếp!")
			TakeCards(a,BoBai,B)
			coruthaykhong=1
			pass
		else:
			print(TenMay[a]+" : Tôi không rút nữa!")
			pass
	elif temprutbai==17:
		ngaunhien=random.randint(1,100)
		if ngaunhien<=60:
			print(TenMay[a]+" : Tôi rút tiếp!")
			TakeCards(a,BoBai,B)
			coruthaykhong=1
			pass
		else:
			print(TenMay[a]+" : Tôi không rút nữa!")
			pass
	elif temprutbai==16:
		ngaunhien=random.randint(1,100)
		if ngaunhien<=90:
			print(TenMay[a]+" : Tôi rút tiếp!")
			TakeCards(a,BoBai,B)
			coruthaykhong=1
			pass
		else:
			print(TenMay[a]+" : Tôi không rút nữa!")
			pass
	elif temprutbai<16:
			print(TenMay[a]+" : Tôi rút tiếp!")
			TakeCards(a,BoBai,B)
			coruthaykhong=1
			pass
	return coruthaykhong

def SumCardPointsNguLinh(b,E):
	DemA=0
	SumCardPoints=[0,0,0,0,0]
	for j in range((b-1)*5,5+(b-1)*5):
		#if DeckCheck(E[j])[0:1]!="A":
		temp0=CardPoints(E[j])
		SumCardPoints[b]=SumCardPoints[b]+temp0
		#else:
			#DemA=DemA+1
	temp1=SumCardPoints[b]
	#tempArray=[1 for i in range(DemA+5)]
	#for k in range(0,DemA+1):
		#tempArray[k]=temp1+10*k+1*(DemA-k)
		#a=tempArray[k]
		#if a<21 and k>0:
			#if (a+k)<=21:
				#a=a+k
			#elif (a+k)>21:
				#a=21
		#tempArray[k]=a
	#temp2=min(tempArray)
	#if temp2>21:
		#temp2=0
	#if temp2<21 and temp2>0:
		#if (temp2+DemA)<=21:
			#temp2=temp2+DemA
		#elif (temp2+DemA)>21:
			#temp2=21
	#if temp2==1:
		#temp2=0
	return temp1

def CheckNguLinh(a,B):
	LenBai(a,B)
	if SumCardPointsNguLinh(a,B)<=21 and SumCardPointsNguLinh(a,B)>0:
		print("Tổng điểm: "+str(SumCardPointsNguLinh(a,B)))
		print("Ngũ linh! "+TenMay[a]+" đã thắng nhà cái!")
	else:
		print("Tổng điểm: "+str(SumCardPointsNguLinh(a,B)))
		print("Ngủ luôn! "+TenMay[a]+" thua gòi!")

def CheckNguLinhNguoiChoi():
	LenBai(1,ListNguoiChoi)
	if SumCardPointsNguLinh(1,ListNguoiChoi)<=21 and SumCardPointsNguLinh(1,ListNguoiChoi)>0:
		print("Tổng điểm: "+str(SumCardPointsNguLinh(1,ListNguoiChoi)))
		print("Ngũ linh! "+TenNguoiChoi+" đã thắng nhà cái!")
		Thangtien()
	else:
		print("Tổng điểm: "+str(SumCardPointsNguLinh(1,ListNguoiChoi)))
		print("Ngủ luôn! "+TenNguoiChoi+" thua gòi!")
		Thuatien()

def Soluongbai(a,B):
	temp=0
	for i in range((a-1)*5,5+(a-1)*5):
		if B[i]!=0:
			temp=temp+1
	return temp

def DoaPhongTay(a,B):
	randomcaudoatrunggian=random.randint(1,30)
	randomcaudoa=randomcaudoatrunggian//10+1
	if randomcaudoa==1:
		print(TenMay[a]+": Đụng vô là phỏng tay à!")
	elif randomcaudoa==2:
		print(TenMay[a]+": Xì dách đó nha!")
	elif randomcaudoa==3:
		print(TenMay[a]+": Suy nghĩ kỹ chưa?")
	elif randomcaudoa==4:
		print(TenMay[a]+": Xét là thua liền")

def Camthanthua(a,B):
	randomcaudoatrunggian=random.randint(1,70)
	randomcaudoa=randomcaudoatrunggian//10+1
	if randomcaudoa==1:
		print(TenMay[a]+": Cay thế nhỡ!")
	elif randomcaudoa==2:
		print(TenMay[a]+": Xui quá!")
	elif randomcaudoa==3:
		print(TenMay[a]+": Đen thôi, đỏ không bao giờ tới!")
	elif randomcaudoa==4:
		print(TenMay[a]+": Thôi đen bạc đỏ tình vậy!")
	elif randomcaudoa==5:
		print(TenMay[a]+": Chán thật sự!")
	elif randomcaudoa==6:
		print(TenMay[a]+": Hết tiền rồi!")
	elif randomcaudoa==7:
		print(TenMay[a]+": Nghi nhà cái chơi ăn gian quá!")
		print("Nhà cái: Ăn nói cẩn thận nha, tui kêu bảo vệ đuổi ra khỏi Casino giờ!")
	elif randomcaudoa==8:
		print(TenMay[a]+": Ê bạn "+TenNguoiChoi+" nãy giờ ăn hay thua? Sao tui xui quá!")

def Camthanthang(a,B):
	randomcaudoatrunggian=random.randint(1,30)
	randomcaudoa=randomcaudoatrunggian//10+1
	if randomcaudoa==1:
		print(TenMay[a]+": Ghê chưa, ghê chưa, ghê chưa?")
	elif randomcaudoa==2:
		print(TenMay[a]+": Đó gọi là đẳng cấp!")
	elif randomcaudoa==3:
		print(TenMay[a]+": Con đã không phụ lòng sư phụ")
	elif randomcaudoa==4:
		print(TenMay[a]+": Ăn hoài ngại quá")
	
def NhaCairutbai():
	temprutbai=SumCardPoints(1,ListNhaCai)
	coruthaykhong=0
	if temprutbai>=20 or temprutbai==0 or Soluongbai(1,ListNhaCai)==5 :
		pass
	elif temprutbai==19:
		ngaunhien=random.randint(1,100)
		if ngaunhien<=5:
			print("Nhà Cái: Để rút thử vận coi sao!")
			TakeCards(1,BoBai,ListNhaCai)
			coruthaykhong=1
			pass
		else:
			print("Nhà Cái: Ngon rồi, xét thôi!")
			pass
	elif temprutbai==17 or temprutbai==18:
		ngaunhien=random.randint(1,100)
		if ngaunhien<=40:
			print("Nhà cái: Ớn quá, rút tiếp!")
			TakeCards(1,BoBai,ListNhaCai)
			coruthaykhong=1
			pass
		else:
			print("Nhà Cái: Ngon rồi, xét thôi!")
			pass
	elif temprutbai<=16:
			print("Nhà cái: Để rút thêm xíu chứ tui non quá!")
			TakeCards(1,BoBai,ListNhaCai)
			coruthaykhong=1
			pass
	return coruthaykhong

def Thangtien():
	global Money
	global Moneycuoc
	Money=Money+Moneycuoc

def Thuatien():
	global Money
	global Moneycuoc
	Money=Money-Moneycuoc

def NhaCaiCheBaiQuac(a,B):
	if SumCardPoints(a,B)==0 and SumCardPoints(1,ListNhaCai)>0:
		print("Nhà cái: Quắc rồi! Vậy mà tỏ ra nguy hiểm!")	

#def PhatDenLang():
	#for i in range (0,Soluongbai(1,ListNguoiChoi)):
		#B=[0,0,0,0,0,0,0,0]
		#for j in range(0,i):
			#B[j]=ListNguoiChoi[j]
		#a=SumCardPoints(1,B)
		#if a>=21 and ListNguoiChoi[i+1]!=0:
			#print("Nhà cái: Phạt đền làng! Bạn "+TenNguoiChoi+" đã quắc rồi vẫn cố rút thêm")
			#for k in range(1,numofcom+2):
				#Thuatien() 
		#break

#def DeckReset(D):
	#D = [1 for i in range(53)]

#def ComCardsReset(ComCards1,p):
	#ComCards1=[0 for i in range(5*p)]
#------------------------------

#I.THÔNG TIN ĐẦU GAME

print("Chào mừng bạn đến với game xì dách")
print("Bạn tên là gì?: ",end="")
TenNguoiChoi=input()
print("Chào "+TenNguoiChoi+". Bạn muốn chơi với bao nhiêu máy?(Tối đa 3 máy): ",end="")
numofcomtemp=input()
global numofcom
numofcomtemp=kiemtraso(numofcomtemp)
numofcom=int(numofcomtemp)
print("Mời bạn đặt tên cho các máy:")
TenMay=[i for i in range(numofcom+5)]
for i in range(1,numofcom+1):
	print("Tên của máy "+str(i)+" là: ",end="")
	TenMay[i]=input()
print("Bạn muốn có bao nhiêu tiền trong tài khoản?: ",end="")
Tien=input()
global Money
Tien=kiemtraso(Tien)
Money=int(Tien)
print("-----------------------------------------")

#II.THIẾT LẬP BỘ BÀI VÀ LIST CHO MÁY, NGƯỜI CHƠI VÀ NHÀ CÁI

CON = "Yes"
while CON=="Yes":
	os.system('cls')
	print("Chúng ta bắt đầu nhé!")
	print("Số tiền bạn hiện có: ",end="")
	print(Money)
	print("Bạn muốn cược bao nhiêu?: ",end="")
	Tiencuoc=input()
	global Moneycuoc
	Tiencuoc=kiemtraso(Tiencuoc)
	Moneycuoc=int(Tiencuoc)
	while Moneycuoc>Money:
		print("Số tiền bạn cược không được phép vượt quá số tiền bạn hiện có. Mời bạn nhập lại: ",end="")
		Tiencuoc=input()
		Tiencuoc=kiemtraso(Tiencuoc)
		Moneycuoc=int(Tiencuoc)

	BoBai=[1 for i in range(53)]
	ListMay=[0 for i in range(5*numofcom)]
	ListNguoiChoi=[0,0,0,0,0,0,0,0,0,0]
	ListNhaCai=[0,0,0,0,0,0,0,0,0,0]

	#III.CHIA 2 LÁ ĐẦU

	for i in range(1,numofcom+1):
		TakeCards(i,BoBai,ListMay)
		TakeCards(i,BoBai,ListMay)

	TakeCards(1,BoBai,ListNguoiChoi)
	TakeCards(1,BoBai,ListNguoiChoi)

	TakeCards(1,BoBai,ListNhaCai)
	TakeCards(1,BoBai,ListNhaCai)

	print(5*"...")

	print("Bài của bạn đây: ",end="")
	for i in range(0,5):
		if ListNguoiChoi[i]>0:
			print(DeckCheck(ListNguoiChoi[i]),end=" | ")
	print("//")
	print(5*"...")

	#IV. KIỂM TRA XÌ BÀN - XÌ DÁCH:
	nhacaixbcheck=NhaCaiXiBan()
	if nhacaixbcheck==1:
		pass
	else:
		cxbm=[0,0,0,0,0,0,0,0]
		cxdm=[0,0,0,0,0,0,0,0]
		dxm=[0,0,0,0,0,0,0,0,0]
		for i in range(1,numofcom+1):
			cxbm[i]=CheckXiBanMay(i,ListMay)
			if cxbm[i]==0:
				cxdm[i]=CheckXiDachMay(i,ListMay)
			else:
				pass

		cxbnc=CheckXiBanNguoiChoi()
		if cxbnc==0:
			cxdnc=CheckXiDachNguoiChoi()
		else:
			pass

		#V. RÚT BÀI

		for i in range(1,numofcom+1):
			temprutthuc=0
			if cxbm[i]==1 or cxdm[i]==1:
				dxm[i]=1
			else:
				while temprutthuc<3:
					print("Nhà cái: Người chơi "+TenMay[i]+" có muốn rút thêm không?")
					t1=Mayrutbai(i,ListMay)
					temprutthuc=temprutthuc+t1
					if t1==0:
						break
				if temprutthuc<=1:
					print("Nhà cái: Người chơi "+TenMay[i]+" dằn sớm thế?")
				elif temprutthuc==0:
					print("Nhà cái: Dằn dơ hả?")
				elif temprutthuc==3:
					print("Nhà cái: Ngũ linh hay ngủ luôn đây?")
					CheckNguLinh(i,ListMay)
					dxm[i]=1
				print(5*"...")

		traloi="Có"
		sobaidarut=0
		dxnc=0
		if cxbnc==1 or cxdnc==1:
			dxnc=1
		else:
			while (traloi == "Có" or traloi=="Co" or traloi=="C" or traloi=="c") and sobaidarut<3 and SumCardPoints(1,ListNguoiChoi)!=0:
				print("Số điểm hiện tại của bạn: "+str(SumCardPoints(1,ListNguoiChoi)))
				print("Nhà cái: Người chơi "+TenNguoiChoi+" có muốn rút thêm không? (Có hoặc Không): ",end="")
				traloimau1=["Có","Co","co","Không","Khong","khong","Ko","ko","k","K","C","c"]
				traloi=input()
				traloi=kiemtracuphap(traloi,traloimau1,"Có hoặc Không")
				if traloi == "Có" or traloi=="Co" or traloi=="C" or traloi=="c":
					sobaidarut=sobaidarut+1
					TakeCards(1,BoBai,ListNguoiChoi)
					print("Bài của bạn đây: ",end="")
					for i in range(0,5):
						if ListNguoiChoi[i]>0:
							print(DeckCheck(ListNguoiChoi[i]),end=" | ")
					print("\n")
				else:
					pass
			if sobaidarut==3:
				CheckNguLinhNguoiChoi()
				dxnc=1
			print(5*"...")

		#V. XÉT BÀI
		while SumCardPoints(1,ListNhaCai)<16 and SumCardPoints(1,ListNhaCai)>0:
			NhaCairutbai()
			print(5*"...")
		while sum(dxm)+dxnc<numofcom+1:
			randomtrunggian=random.randint(1,(numofcom)*10)
			randomxetbai=randomtrunggian//10+1
			if randomxetbai==numofcom+1 and dxnc==0:
				print("Nhà cái: Để tui xét bạn "+TenNguoiChoi+" coi sao.")
				if SumCardPoints(1,ListNhaCai)<SumCardPoints(1,ListNguoiChoi):
					randomtrunggianbocthem=random.randint(1,100)
					if randomtrunggianbocthem<=70:
						NhaCairutbai()
					if randomtrunggianbocthem>70:
						pass
					if SumCardPoints(1,ListNhaCai)==0:
						pass
				if Soluongbai(1,ListNhaCai)==5 and SumCardPointsNguLinh(1,ListNhaCai)<=21:
					print("Nhà cái ngũ linh!")
					LenBai(1,ListNhaCai)
					for i in range(1,numofcom+1):
						if dxm[i]==0:
							print("Bạn "+TenMay[i]+" đã thua nhà cái!")
						else:
							pass
					if dxnc==0:
						print("Bạn "+TenNguoiChoi+" đã thua nhà cái!")
				else:		
					LenBai(1,ListNguoiChoi)
					NhaCaiCheBaiQuac(1,ListNguoiChoi)
					SoBaiNhaCaiVoiNguoiChoi()
					#PhatDenLang()
					dxnc=1
				print(5*"...")
			elif randomxetbai<=numofcom and dxm[randomxetbai]==0:
				print("Nhà cái: Để tui xét bạn "+TenMay[randomxetbai]+" coi sao.")
				if SumCardPoints(1,ListNhaCai)<SumCardPoints(randomxetbai,ListMay):
					randomtrunggianbocthem=random.randint(1,100)
					if randomtrunggianbocthem<=70:
						NhaCairutbai()
					if randomtrunggianbocthem>70:
						pass
					if SumCardPoints(1,ListNhaCai)==0:
						pass
				if Soluongbai(1,ListNhaCai)==5 and SumCardPointsNguLinh(1,ListNhaCai)<=21:
					print("Nhà cái ngũ linh!")
					LenBai(1,ListNhaCai)
					for i in range(1,numofcom+1):
						if dxm[i]==0:
							print("Bạn "+TenMay[i]+" đã thua nhà cái!")
						else:
							pass
					if dxnc==0:
						print("Bạn "+TenNguoiChoi+" đã thua nhà cái!")
				else:	
					DoaPhongTay(randomxetbai,ListMay)	
					LenBai(randomxetbai,ListMay)
					NhaCaiCheBaiQuac(randomxetbai,ListMay)
					SoBaiNhaCaiVoiMay(randomxetbai)
					if Soluongbai(randomxetbai,ListMay)==2 and SumCardPoints(randomxetbai,ListMay)<=17:
						print("Nhà cái: Dằn dơ nha!")
					dxm[randomxetbai]=1
				print(5*"...")
			else:
				pass

		print("Mời xem bài nhà cái:")
		LenBai(1,ListNhaCai)
		print(5*"...")
		print("Số tiền hiện tại của bạn là: ",end="")
		print(Money)
	print(5*"...")
	print("Bạn muốn tiếp tục chứ? (Gõ Yes hoặc No)")
	if Money==0:
		print("Bạn đã thua hết tiền. Trò chơi kết thúc!")	
		CON="No"
	else:
		CON=input()
	while not CON == "Yes" and not CON == "No":
		print("Bạn nhập sai cú pháp rồi. Mời bạn nhập lại (Gõ Yes hoặc No):")
		CON = input()
print("Cảm ơn bạn đã chơi game.Mời bạn đánh giá cho game (1-5 sao): ") 
c=input()
c=kiemtraso(c)
d=int(c)
while d>5 or d<1:
	print("Bạn nhập sai cú pháp rồi. Mời bạn nhập lại (1-5 sao):")
	c=input()
	c=kiemtraso(c)
	d=int(c)



