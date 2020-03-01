#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <algorithm>

// option -D compilateur




class Game{

	public:


	std::byte game_tab[H][W] = {(std::byte)0};


	std::byte player1 = (std::byte)1;
	std::byte player2 = (std::byte)2;

	std::byte vide = (std::byte)0;









	void minimax(std::byte player) {
		if(player == (std::byte)1){
		int m = -1000;
		int played;
		int tmp, maxj;

		for(int i = 0; i < W; i++) {
				if(game_tab[0][i] == vide) {
					played = play(player,i);
					tmp = maxi();

					if(tmp > m) {
						m = tmp;
						maxj = i;
					}

					unplay(played);
				}

		}

		play(player,maxj);
	}

	if(player == (std::byte)2){
		int m = 1000;
		int played;
		int tmp, maxj;

		for(int i = 0; i < W; i++) {
				if(game_tab[0][i] == vide) {
					played = play(player,i);
					tmp = mini();

					if(tmp < m) {
						m = tmp;
						maxj = i;
					}

					unplay(played);
				}


		}

		play(player,maxj);

	}
	}



int maxi(){
	if(tableau_rempli() == true || score()){
		return eval();
	}

	int tmp;
	int m = -1000;
	int played;

	for(int i = 0;i < W;++i){
		if(game_tab[0][i] == vide){
			played = play(player2,i);
			tmp = mini();

			if(tmp > m){
					m = tmp;
			}

			unplay(played);

		}
	}
	return m;
}



int mini(){
	if(tableau_rempli() == true|| score()){
		return eval();
	}

	int tmp;
	int played;
	int m = 1000;

	for(int i = 0;i < W;++i){
		if(game_tab[0][i] == vide){
			played = play(player1,i);
			tmp = maxi();

			if(tmp < m){
					m = tmp;
			}

			unplay(played);

		}
	}
	return m;
}


int nbr_pieces(void) {
	int n = 0;
	for(int i = 0; i < H; i++) {
			for(int j = 0; j < W;++j){
				if(game_tab[i][j]!= vide)
					n++;
				}
	}
	return n;
}



int victoire(int y,int x,std::byte value) {
	int inc = 1;
	int align = 1;
	while(inc + y < W && align < 4) {
		if(game_tab[x][y + inc] != value)
			break;
		align++;
		inc++;
	}
	inc = 1;
	while(y - inc >= 0 && align < 4) {
		if(game_tab[x][y - inc] != value)
			break;
		align++;
		inc++;
	}

	if(align >= 4)
		return true;

	inc = 1;
	align = 1;
	while(x + inc < H && align < 4) {
		if(game_tab[x + inc][y] != value)
			break;
		align++;
		inc++;
	}

	inc = 1;
	while(x - inc >= 0 && align < 4) {
		if(game_tab[x - inc][y] != value)
			break;
		align++;
		inc++;
	}

	if(align >= 4){
		return true;
	}

	else{
		return false;
	}

}




int score(){


	for(int p = 1; p <= 2; p++) {
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
					if(game_tab[i][j] != vide && victoire(i,j,std::byte(p)) == 1){
						return p;
					}
			}
		}
	}

	if(tableau_rempli() == 1) return 3;

	return 0;

}







int eval(){
	int score_ = score();
	int nb_pieces = nbr_pieces();

	switch(score_){
		case 1:
			return 1000 - nb_pieces;
			break;
		case 2:
			return -1000 + nb_pieces;
			break;
		case 3:
			return 0;
	}

	return nb_pieces;


}



	int play(std::byte player, int col){
		if(col > W && col < 0 && tableau_rempli() == 1){
			return -1;
		}
			for(int i = H - 1;i > -1;--i){
				if(game_tab[i][col] == vide){
					game_tab[i][col] = player;
					break;

				}
			}

		return col;

		}

		void unplay(int col){
				for(int i = 0;i < H;++i){
					if(game_tab[i][col] != vide){
						game_tab[i][col] = vide;
						return;

					}
				}

		}







		void print_state(){
			for(int i = 0 ; i < H;++i){
				for(int j = 0; j< W;++j){
					std::cout << int(game_tab[i][j]) << "|";
				}
				std::cout << "\n";
			}
			std::cout << "-----------------------------------------------\n";
		}


		bool tableau_rempli(){
			for(int i = 0; i < H; ++i){
				for(int j = 0; j < W;++j){
					if(game_tab[i][j] == vide){
						return false;
					}

			}
		}
			return true;
		}


};



/*

int minimax(){

}


*/


int main(){



Game test;

while(test.tableau_rempli() == false){

	test.minimax((std::byte)1);



	test.minimax((std::byte)2);

	test.print_state();


}




}
