%%  清空环境变量
clear all
clc
%%  产生训练集
%导入数据
load iris_data.mat
%随机产生训练集和测试集
p1=[];
t1=[];
p2=[];
t2=[];
for i=1:3
    temp_input=features((i-1)*50+1:i*50,:);
    temp_output=classes((i-1)*50+1:i*50,:);
    n=randperm(50);
    %训练集——120个样本
    p1=[p1 temp_input(n(1:40),:)'];
    t1=[t1 temp_output(n(1:40),:)'];
    %测试集——30个样本
    p2=[p2 temp_input(n(41:50),:)'];
    t2=[t2 temp_output(n(41:50),:)'];
end
%%  建立模型
res1=[];
res2=[];
time1=[];
time2=[];
for i = 1:4
    for j = i:4
        p_1=p1(i:j,:);
        p_2=p2(i:j,:);
        %GRNN创建以及仿真测试
        t=cputime;
        %创建网络
        net1=newgrnn(p_1,t1);
        %仿真测试
        t_sim1=sim(net1,p_2);
        T_sim1=round(t_sim1);
        t=cputime-t;
        time1=[time1 t];
        res1=[res1 T_sim1'];
        %PNN创建及仿真测试
        t=cputime;
        Tc1=ind2vec(t1);
        %创建网络
        net2=newpnn(p_1,Tc1);
        %仿真测试
        Tc2=ind2vec(t2);
        t_sim2=sim(net2,p_2);
        T_sim2=vec2ind(t_sim2);
        t=cputime-t;
        time2=[time2 t];
        res2=[res2 T_sim2']
    end
end
%%  性能评价
acc1=[];
acc2=[];
time=[];
for i=1:10
    acc_1=length(find(res1(:,i)==t2')/length(t2));
    acc_2=length(find(res2(:,i)==t2')/length(t2));
    acc1=[acc1 acc_1];
    acc2=[acc2 acc_2];
end
%结果对比
result=[t2' res1 res2]
acc=[acc1;acc2]
time=[time1;time2]
%%画图
figure(1)
plot(1:30,t2,'bo',1:30,res1(:,4),'r-*',1:30,res2(:,4),'k:^')
grid on
xlabel('测试集样本编号')
ylabel('测试集样本类别')
string={'测试集预测结果对比（GRNN vs PNN）';['正确率：' num2str(acc1(4)*100) '%(GRNN) vs ' num2str(acc2(4)*100) '%(PNN)']};
title(string);
legend('真实值','GRNN预测值','PNN预测值')
figure(2)
plot(1:10,acc(1,:),'r-*',1:10,acc(2,:),'b:o')
grid on
xlabel('模型编号')
ylabel('测试集正确率')
title('10个模型的测试集正确率对比（GRNN vs PNN）')
legend('GRNN','PNN')
figure(3)
plot(1:10,time(1,:),'r-*',1:10,time(2,:),'b:o')
grid on
xlabel('模型编号')
ylabel('运行时间（s）')
title('10个模型的运行时间对比（GRNN vs PNN）')
legend('GRNN','PNN')

