/**
* 使用递归函数逆序一个栈
     */
    public void reverse(Stack<Integer> stack){
        if(stack.isEmpty()){
            return;
        }
        int lastEle = removeBottom(stack);//拿到栈中最底下的一个元素
        reverse(stack);
        stack.push(lastEle);

    }

    private int removeBottom(Stack<Integer> stack) {
        Integer ele = stack.pop();
        if(stack.isEmpty()){
            return ele;
        }else{
            Integer res = removeBottom(stack);
            stack.push(ele);
            return res;
        }
    }