# 形成一个动态链接的共享库
libmymath.so:sub.o add.o
	gcc -shared -o $@ $^
#产生.o目标文件，程序内部的地址方案是：与位置无关，库文件可以在内存的任何位置加载，而且不影响其他程序的关联性
%.o:%.c
	gcc -fPIC -c $<

.PHONY:clean
clean:
	rm -rf libmymath.so *.o lib

.PHONY:lib
lib:
	mkdir lib
	cp *h lib
	cp libmymath.so lib







# 形成静态库，上面没有注释的部分是形成动态库的

# libmymath.a:sub.o add.o
# 	ar -rc $@ $^
# %.o:%.c
# 	gcc -c $<

# .PHONY:clean
# clean:
# 	rm -rf *.o output libmymath.a

# .PHONY:output	
# output:
# 	mkdir output 
# 	cp -rf *.h output 
# 	cp libmymath.a output
