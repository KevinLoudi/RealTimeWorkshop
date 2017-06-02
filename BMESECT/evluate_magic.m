%Check if Magic matrx have expected proporties.
function f=evluate_magic(n)
    n=int16(n);
    if(nargin<1 | n<0)
        error('Illegal input!!');
    end
    flag=1;
    
	if(n>2)
        fix_sum=n*(n^2+1)/2;
		x=magic(n)
        %calculate row sum
		for j=1:n
			sum_row=0;
			for i=1:n
				sum_row=sum_row+x(j,i);
            end
            %check if the sum is expected
            if(sum_row~=fix_sum)
                sum_row
                flag=0
                warning('Unexpected sum!!');
            end
        end
        
        %calculate col sum
		for i=1:n
			sum_col=0;
			for j=1:n
				sum_col=sum_col+x(j,i);
            end
            %check if the sum is expected
            if(sum_col~=fix_sum)
                sum_col
                flag=0;
                warning('Unexpected sum!!');
            end
        end
        
        %calculate diag sum
        sum_diag=sum((diag(x))');
        if(sum_diag~=fix_sum)
                sum_diag
                flag=0;
                warning('Unexpected sum!!');
         end
    else
        warning('Matrix dimension should be more than 2!!!');
        return
    end
    display('Magic matrix follow the expectation...');
    return
end  
