SRCS = student.c stud_add.c stud_delall.c stud_del.c stud_mod.c stud_reverse.c stud_save.c stud_show.c stud_sort.c

OBJS = $(SRCS:.c=.o)

HEADERS = stud_struct.h

TARGET = student

all: $(TARGET)

$(TARGET): $(OBJS)
	$ cc $(OBJS) -o $(TARGET)


%.o: %.c $(HEADERS)
	$ cc -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

