cd 'D:\Code\Techjoin\BMESECT';
%% common commands
ver;  %see version
dir;  %file folder
cd '..\'  %jump up
path=which('Script1.m');  %show file path

%% vector and array
i,j,
%constructing symbolic variables and represent complex number
syms('a','b','c'); a=3; b=4; z=a+b*j, 
syms('A','theta'); theta=0.5236; A=1; z=A*exp(theta*j),
realmin, realmax, eps,

clear; clc;
a=10:3:30,
b=[1 2 3; 4 5 6],
b(:,1)=[],

c=magic(4),
cf=c(find(c>2)),

a=[1, 2*pi; sqrt(3), 4+5j],
b=a',
c=linspace(1,10,6),
d=logspace(1,10,6),

%% Matrix calculation
clear; clc;
% syms('k','A','B','C','D');
% k=6;
% A=[1 1 2; 3 5 8; 13 21 34],
% B=k.*A,
% k.*A==A.*k,
% C=[8 8 8; 5 5 5; 1 1 1],
% A.*C==C.*A,
% A*C==C*A,
% D=A./k,
% D=k./A,
% C=[1 2 8; 4 12 6; 69 8 9]
% D=inv(C),

% A=sym('[a11 a12; a21 a22]'); B=det(A),
% A=sym('[a11 a12 a13; a21 a22 a23; a31 a32 a33]'); B=det(A),
% B=inv(A),
% A*B,
% B=pinv(A),
% A*B,

% A=[1 3 -2; -1 2 4; 502 497 -490];
% A1=inv(A), 
% B1=A1*A, B1=A*A1,
% d=rank(A), %�������
% [V,D]=eig(A), %���������ֵ����������
% A*V==V*D, %D: ����ֵ����V:������������

% A=pascal(3),
% R=chol(A),
% R'*R==A, %Cholesky�ֽ�
% [L,U]=lu(A), %LU�ֽ�
% L*U==A,
% b=[1 2 3]',x=U\(L\b), %���
% det(A)==det(L)*det(U), 

% A=[1 1 1;2 -1 -1; 2 -4 5];
% [Q,R,E]=qr(A), %E: �û����� Q: �������� R: �����Ǿ���
% QTQ=Q.'*Q,
% B=Q*R, C=A*E,
% A*E==Q*R,

% A=[9 8;6 8];
% ATA=A'*A, [V,D]=eig(ATA), sigma=sqrt(D), %����ֵ������ƽ����
% [U,S,V]=svd(A), %����ֵ�ֽ�
% UTU=U.'*U, VTV=V.'*V, %U��VΪ��������
% USV=U*S*V', %SVD�ֽ�

A=eye(3,3), %��λ����

%% Polynomial
clear; clc;
% p=[5 4 3 2 1]; roots(p), %ָ��ϵ�������ʽ��
% p1=poly([2,3,4]), %�ɶ���ʽ�ĸ���ϵ��
% y=polyval(p,8), %x=8ʱ����ʽ��ֵ

% p=[1 3 5]; q=[2 4 6];
% r=conv(p,q), s=deconv(r,p), %p,q����õ�r; r,q������õ�p
% p1=polyder(p), %����ʽ����

x=[1 2 3 4 5];
y=[5.5 43.1 128 290.7 498.4];
p=polyfit(x,y,4), %4�׶���ʽ���
X=[2 4 5;-1 0 3;7 1 5];
Y=polyval(p,X), %����ʽ��ֵ
Z=polyvalm(p,X), %����ʽ��ֵ--����Ϊ����

sym('y=1/(a*log(1-x-a)+c1)')
sym('f=2*log(t)*exp(t)*sqrt(pi)')
sym('z=sin(abs(x)+abs(y))/sqrt(cos(aabs(x+y)))')
sym('F=z/(z-exp(T*log(8)))')

%% Symbolic calculation
clear; clc;
syms('x','y');
collect(x^2*y+y*x-x^2-2*x) %Collect coefficients.�ϲ�ͬ����

syms x a b c d;
int(x)
int(x^2,a,b)
p=[a b; c d];
inver_p=inv(p)





