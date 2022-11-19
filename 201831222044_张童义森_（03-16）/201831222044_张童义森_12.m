%%  ��ջ�������
clear all
clc
%%  ����ѵ����
%��������
load iris_data.mat
%�������ѵ�����Ͳ��Լ�
p1=[];
t1=[];
p2=[];
t2=[];
for i=1:3
    temp_input=features((i-1)*50+1:i*50,:);
    temp_output=classes((i-1)*50+1:i*50,:);
    n=randperm(50);
    %ѵ��������120������
    p1=[p1 temp_input(n(1:40),:)'];
    t1=[t1 temp_output(n(1:40),:)'];
    %���Լ�����30������
    p2=[p2 temp_input(n(41:50),:)'];
    t2=[t2 temp_output(n(41:50),:)'];
end
%%  ����ģ��
res1=[];
res2=[];
time1=[];
time2=[];
for i = 1:4
    for j = i:4
        p_1=p1(i:j,:);
        p_2=p2(i:j,:);
        %GRNN�����Լ��������
        t=cputime;
        %��������
        net1=newgrnn(p_1,t1);
        %�������
        t_sim1=sim(net1,p_2);
        T_sim1=round(t_sim1);
        t=cputime-t;
        time1=[time1 t];
        res1=[res1 T_sim1'];
        %PNN�������������
        t=cputime;
        Tc1=ind2vec(t1);
        %��������
        net2=newpnn(p_1,Tc1);
        %�������
        Tc2=ind2vec(t2);
        t_sim2=sim(net2,p_2);
        T_sim2=vec2ind(t_sim2);
        t=cputime-t;
        time2=[time2 t];
        res2=[res2 T_sim2']
    end
end
%%  ��������
acc1=[];
acc2=[];
time=[];
for i=1:10
    acc_1=length(find(res1(:,i)==t2')/length(t2));
    acc_2=length(find(res2(:,i)==t2')/length(t2));
    acc1=[acc1 acc_1];
    acc2=[acc2 acc_2];
end
%����Ա�
result=[t2' res1 res2]
acc=[acc1;acc2]
time=[time1;time2]
%%��ͼ
figure(1)
plot(1:30,t2,'bo',1:30,res1(:,4),'r-*',1:30,res2(:,4),'k:^')
grid on
xlabel('���Լ��������')
ylabel('���Լ��������')
string={'���Լ�Ԥ�����Աȣ�GRNN vs PNN��';['��ȷ�ʣ�' num2str(acc1(4)*100) '%(GRNN) vs ' num2str(acc2(4)*100) '%(PNN)']};
title(string);
legend('��ʵֵ','GRNNԤ��ֵ','PNNԤ��ֵ')
figure(2)
plot(1:10,acc(1,:),'r-*',1:10,acc(2,:),'b:o')
grid on
xlabel('ģ�ͱ��')
ylabel('���Լ���ȷ��')
title('10��ģ�͵Ĳ��Լ���ȷ�ʶԱȣ�GRNN vs PNN��')
legend('GRNN','PNN')
figure(3)
plot(1:10,time(1,:),'r-*',1:10,time(2,:),'b:o')
grid on
xlabel('ģ�ͱ��')
ylabel('����ʱ�䣨s��')
title('10��ģ�͵�����ʱ��Աȣ�GRNN vs PNN��')
legend('GRNN','PNN')

