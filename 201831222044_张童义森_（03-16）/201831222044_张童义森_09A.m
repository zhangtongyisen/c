function Queens
% 8皇后问题的递归法求解
sol = 1; % 解的个数
queen = zeros(8); % 8*8的棋盘
saferows = true(1,8); % 用来表示每一行是否是安全位置
safeleftdiag = true(1,15); % 用来表示左对角是否安全，在同一个左对角上的元素满足i1+j1 = i2 + j2;
saferightdiag = true(1,15);% 用来表示左对角是否安全，在同一个右对角上的元素满足i1-j1 = i2 - j2;
trycol(1); % 检查第一列是否可以放置皇后
% 该函数用来检查第col列是否可以方位皇后
    function trycol(col)
        % 对行循环，一行一行的去放
        for row = 1 : 8
            % 检查第row行第col列的位置是否安全
            if safe(row,col)
                % 如果安全，该位置被占据,该行和对角不安全
                [saferows(row),safeleftdiag(row + col - 1),saferightdiag(row - col + 8)]=deal(false);
                queen(row,col) = 1;
                % 如果是第8列，说明解完成，输出
                if col == 8
                    fprintf('第%d个解\n',sol);
                    disp(queen);
                    sol = sol + 1;
                else % 否则，去试探下一列
                    trycol(col + 1);
                end
                % 判断完该行，就去判断下一行，应该清除该行的占据信息和安全信息
                [saferows(row),safeleftdiag(row + col - 1),saferightdiag(row - col + 8)]=deal(true);
                queen(row,col) = 0;
            end
            
        end
    end
% 该函数用来检查第row行第col列的位置是否安全
    function y = safe(row,col)
        % 检查该列的行，左对角，右对角是否安全
        y = saferows(row) & safeleftdiag(row + col - 1) & saferightdiag(row - col + 8);
    end
end
