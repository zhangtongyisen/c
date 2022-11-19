function Queens
% 8�ʺ�����ĵݹ鷨���
sol = 1; % ��ĸ���
queen = zeros(8); % 8*8������
saferows = true(1,8); % ������ʾÿһ���Ƿ��ǰ�ȫλ��
safeleftdiag = true(1,15); % ������ʾ��Խ��Ƿ�ȫ����ͬһ����Խ��ϵ�Ԫ������i1+j1 = i2 + j2;
saferightdiag = true(1,15);% ������ʾ��Խ��Ƿ�ȫ����ͬһ���ҶԽ��ϵ�Ԫ������i1-j1 = i2 - j2;
trycol(1); % ����һ���Ƿ���Է��ûʺ�
% �ú�����������col���Ƿ���Է�λ�ʺ�
    function trycol(col)
        % ����ѭ����һ��һ�е�ȥ��
        for row = 1 : 8
            % ����row�е�col�е�λ���Ƿ�ȫ
            if safe(row,col)
                % �����ȫ����λ�ñ�ռ��,���кͶԽǲ���ȫ
                [saferows(row),safeleftdiag(row + col - 1),saferightdiag(row - col + 8)]=deal(false);
                queen(row,col) = 1;
                % ����ǵ�8�У�˵������ɣ����
                if col == 8
                    fprintf('��%d����\n',sol);
                    disp(queen);
                    sol = sol + 1;
                else % ����ȥ��̽��һ��
                    trycol(col + 1);
                end
                % �ж�����У���ȥ�ж���һ�У�Ӧ��������е�ռ����Ϣ�Ͱ�ȫ��Ϣ
                [saferows(row),safeleftdiag(row + col - 1),saferightdiag(row - col + 8)]=deal(true);
                queen(row,col) = 0;
            end
            
        end
    end
% �ú�����������row�е�col�е�λ���Ƿ�ȫ
    function y = safe(row,col)
        % �����е��У���Խǣ��ҶԽ��Ƿ�ȫ
        y = saferows(row) & safeleftdiag(row + col - 1) & saferightdiag(row - col + 8);
    end
end
