all:
	g++ -w -g -Wall -Iinclude main.cpp -o wavplay -Llib -lboost_system -lsndfile
