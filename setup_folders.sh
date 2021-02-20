
# colors
GREEN=$'\033[92m'
RED=$'\033[91m'
WHITE=$'\033[97m'
MUTED=$'\033[1;30m'
RESET=$'\033[0m'
BOLD=$'\033[1m'
CYAN=$'\033[46;1m'
BG_GRAY=$'\033[48;5;237m'"$WHITE$BOLD"
BG_GREEN=$'\033[48;5;28m'"$WHITE$BOLD"
BG_RED=$'\033[48;5;9m'"$WHITE$BOLD"
CLEAR_LINE=$'\033[0K'


print_header () {
	cd ~
	echo
	echo
	echo $RESET$CYAN" Setting up $1 "$RESET$MUTED
	[ -d $1 ] || mkdir $1
	cd $1
}

create_my_repository () {
	if [ ! -d romeu.$1 ]; then
		git clone git@github.com:romeumc/$1.git romeu.$1
		echo "RED=\$'\\033[91m'" > copy_folder_for_testing.sh
		echo "if [ ! \$1 ]; then" >> copy_folder_for_testing.sh
		echo "echo \$RED \"FOLDER MISSING as parameter 1\"" >> copy_folder_for_testing.sh
		echo "else" >> copy_folder_for_testing.sh
		echo "	[ ! -d $1 ] || rm -rf $1" >> copy_folder_for_testing.sh
		echo "	mkdir $1" >> copy_folder_for_testing.sh
		echo "	cd $1" >> copy_folder_for_testing.sh
		echo "	touch \${1//\//.}" >> copy_folder_for_testing.sh
		echo "	cp -r ../\$1/* ." >> copy_folder_for_testing.sh
		echo "fi" >> copy_folder_for_testing.sh
		chmod 744 copy_folder_for_testing.sh
		./copy_folder_for_testing.sh romeu.$1
	fi
}


# ************** PiscineC ******************
cd ~
echo $CYAN" Setting up PiscineC "$RESET$MUTED
[ -d PiscineC ] || git clone git@github.com:romeumc/PiscineC.git PiscineC


# ************** LIBFT ******************
print_header "Libft"
create_my_repository "libft"

test=test1; user=jtoty; project=Libftest
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	./$test.$user.$project/grademe.sh
	echo $MUTED
	sed -i 's|PATH_LIBFT=~|PATH_LIBFT=~/Libft|' $test.$user.$project/my_config.sh
	echo "bash $test.$user.$project/grademe.sh \$1 \$2 \$3" > t1.sh
	chmod 744 t1.sh
fi

test=test2; user=romeumc; project=libft-unit-test
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	echo "make f -C $test.$user.$project" > t2.sh
	chmod 744 t2.sh
fi

test=test3; user=t0mm4rx; project=libftdestructor
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	echo "cd $test.$user.$project" > t3.sh
	echo "bash run.sh ~/Libft/libft" >> t3.sh
	echo "cd .." >> t3.sh
	chmod 744 t3.sh
fi

test=test4; user=Tripouille; project=libftTester
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	sed -i 's|[.][.]|../libft/|' $test.$user.$project/Makefile
	echo "make a -C $test.$user.$project" > t4.sh
	chmod 744 t4.sh
fi

[ -d helper-sites ] || mkdir helper-sites
cd helper-sites
[ -d Glagan ]		|| git clone git@github.com:Glagan/42-libft.git Glagan
[ -d ska42 ]		|| git clone git@github.com:ska42/libft.git ska42
[ -d wescande ]		|| git clone git@github.com:wescande/libft.git wescande
if [ ! -d humblEgo ]; then
	git clone https://github.com/humblEgo/42_cursus.git humblEgo
	cd humblEgo
	git checkout d3ada12
	cd ..
fi
echo $RESET




# ************** GetNextLine ******************
print_header "GetNextLine"
create_my_repository "get_next_line"

test=test0; user=romeumc; project=get_next_line_test
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
fi

test=test1; user=Mazoise; project=42TESTERS-GNL
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	sed -i 's|[.][.]|../get_next_line|g' $test.$user.$project/*.sh
	echo "cd $test.$user.$project" > t1.sh
	echo "bash all_tests_with_bonus.sh" >> t1.sh
	echo "cd .." >> t1.sh
	chmod 744 t1.sh
fi

test=test2; user=mrjvs; project=42cursus_gnl_tests
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	chmod 744 $test.$user.$project/*.sh
	sed -i 's|[.]/get_next_line|../get_next_line|' $test.$user.$project/Makefile
	sed -i 's|BONUS=no|BONUS=yes|' $test.$user.$project/Makefile
	echo "make -C $test.$user.$project" >> t2.sh
	chmod 744 t2.sh
fi

test=test3; user=TinfoilPancakes; project=get-next-line-testing-tools
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	cp test0.romeumc.get_next_line_test/gnl_test.c $test.$user.$project
	echo "make buff_all -C $test.$user.$project" > t3.sh
	echo "make mtest_all -C $test.$user.$project" >> t3.sh
	chmod 744 t3.sh
fi

test=test4; user=DontBreakAlex; project=gnlkiller
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	sed -i 's|echo|echo -e|' $test.$user.$project/run.sh
	sed -i '17i#include <signal.h>' $test.$user.$project/test.c
	echo "cd $test.$user.$project" > t4.sh
	echo "cp ../get_next_line/get_next_line.h ." >> t4.sh
	echo "cp ../get_next_line/get_next_line.c ." >> t4.sh
	echo "cp ../get_next_line/get_next_line_utils.c ." >> t4.sh
	echo "cp ../get_next_line/get_next_line_bonus.h ." >> t4.sh
	echo "cp ../get_next_line/get_next_line_bonus.c ." >> t4.sh
	echo "cp ../get_next_line/get_next_line_utils_bonus.c ." >> t4.sh
	echo "bash run.sh" >> t4.sh
	echo "cd .." >> t4.sh
	chmod 744 t4.sh
fi

test=test5; user=charMstr; project=GNL_lover
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	sed -i 's|echo|echo -e|' $test.$user.$project/GNL_lover.sh
	echo "cd $test.$user.$project" > t5.sh
	echo "cp ../get_next_line/get_next_line.h copy_in_here_GNL_files" >> t5.sh
	echo "cp ../get_next_line/get_next_line.c copy_in_here_GNL_files" >> t5.sh
	echo "cp ../get_next_line/get_next_line_utils.c copy_in_here_GNL_files" >> t5.sh
	echo "cp ../get_next_line/get_next_line_bonus.h copy_in_here_GNL_files" >> t5.sh
	echo "cp ../get_next_line/get_next_line_bonus.c copy_in_here_GNL_files" >> t5.sh
	echo "cp ../get_next_line/get_next_line_utils_bonus.c copy_in_here_GNL_files" >> t5.sh
	echo "bash GNL_lover.sh" >> t5.sh
	echo "cd .." >> t5.sh
	chmod 744 t5.sh
fi

test=test6; user=Hellio404; project=Get_Next_Line_Tester
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	sed -i 's|PATH_GNL = [.][.]|PATH_GNL = ../get_next_line|' $test.$user.$project/Makefile
	echo "cd $test.$user.$project" > t6.sh
	echo "sh run.sh" >> t6.sh
	echo "cd .." >> t6.sh
	chmod 744 t6.sh
fi

test=test7; user=Tripouille; project=gnlTester
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	sed -i 's|[.][.]|../get_next_line|g' $test.$user.$project/Makefile
	echo "cd $test.$user.$project" > t7.sh
	echo "make a" >> t7.sh
	echo "cd .." >> t7.sh
	chmod 744 t7.sh
fi

[ -d helper-sites ]	|| mkdir helper-sites
cd helper-sites
[ -d jraleman ]		|| git clone git@github.com:jraleman/42_get_next_line.git jraleman
[ -d cdittric ]		|| git clone git@github.com:cdittric/get_next_line.git cdittric
[ -d MikeFMeyer ]	|| git clone git@github.com:MikeFMeyer/GNL.git MikeFMeyer
[ -d t0mm4rx ]		|| git clone git@github.com:t0mm4rx/get_next_line.git t0mm4rx
[ -d ska42 ]		|| git clone git@github.com:ska42/get_next_line.git ska42
[ -d Olbrien ]		|| git clone git@github.com:Olbrien/ft_get_next_line.git Olbrien
echo $RESET



# ************** ft_Printf ******************
print_header "ftPrintf"
create_my_repository "ft_printf"

test=test1; user=gavinfielder; project=pft
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	sed -i s/"INCLUDE_LIBPTHREAD=0"/"INCLUDE_LIBPTHREAD=1"/ $test.$user.$project/options-config.ini
	sed -i s/"SEND_USAGE_STATISTICS=1"/"SEND_USAGE_STATISTICS=0"/ $test.$user.$project/options-config.ini
	sed -i s/"LIBFTPRINTF_DIR=.."/"LIBFTPRINTF_DIR=..\/ft_printf"/ $test.$user.$project/options-config.ini
	echo "cd $test.$user.$project" > t1.sh
	echo "make" >> t1.sh
	echo "./test \$1" >> t1.sh
	echo "cd .." >> t1.sh
	chmod 744 t1.sh
fi

# é igual ao Gavinfielder
# test=test2; user=cclaude42; project=PFT_2019
# if [ ! -d $test.$user.$project ]; then
# 	git clone git@github.com:$user/$project.git $test.$user.$project
# fi

test=test2; user=charMstr; project=printf_lover_v2
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	sed -i 's|../|../ft_printf/|' $test.$user.$project/config.sh
	echo "cd $test.$user.$project" > t2.sh
	echo "bash printf_lover.sh" >> t2.sh
	echo "cd .." >> t2.sh
	chmod 744 t2.sh
fi

test=test3; user=Mazoise; project=42TESTERS-PRINTF
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	sed -i 's|../../|../../ft_printf/|' $test.$user.$project/srcs/Makefile
	echo "cd $test.$user.$project" > t3.sh
	echo "bash runtest.sh" >> t3.sh
	echo "cd .." >> t3.sh
	chmod 744 t3.sh
fi

test=test4; user=AntoineBourin; project=printf-tester
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	echo "cd $test.$user.$project" > t4.sh
	echo "make -C ../ft_printf/" >> t4.sh
	echo "cp ../ft_printf/libftprintf.a ." >> t4.sh
	echo "bash test.sh" >> t4.sh
	echo "cd .." >> t4.sh
	chmod 744 t4.sh
fi

test=test5; user=cacharle; project=ft_printf_test
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	echo "cd $test.$user.$project" > t5.sh
	echo "make run" >> t5.sh
	echo "cd .." >> t5.sh
	chmod 744 t5.sh
fi

test=test6; user=PandaCoustik; project=Test-42
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	echo "cd $test.$user.$project/test_printf_classic" > t6.sh
	echo "make -C ../../ft_printf/" >> t6.sh
	echo "cp ../../ft_printf/libftprintf.a ." >> t6.sh
	echo "make" >> t6.sh
	echo "cd .." >> t6.sh
	chmod 744 t6.sh
fi

test=test7; user=Tripouille; project=printfTester
if [ ! -d $test.$user.$project ]; then
	git clone git@github.com:$user/$project.git $test.$user.$project
	sed -i 's|[.][.]|../ft_printf|g' $test.$user.$project/Makefile
	echo "cd $test.$user.$project" > t7.sh
	echo "make \$1" >> t7.sh
	echo "cd .." >> t7.sh
	chmod 744 t7.sh
fi


[ -d helper-sites ]	|| mkdir helper-sites
cd helper-sites
[ -d Olbrien ]		|| git clone git@github.com:Olbrien/ft_printf.git Olbrien
echo $RESET