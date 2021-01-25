class game {
    int card [13][4];
    int p1_n[13],p1_s[13];
    int p1_cover_n[13],p1_cover_s[13];
    int p2_n[13],p2_s[13];
    int p2_cover_n[13],p2_cover_s[13];
    int p3_n[13],p3_s[13];
    int p3_cover_n[13],p3_cover_s[13];
    int user_n[13],user_s[13];
    int user_cover_n[13],user_cover_s[13];
    int central_card[13][4];
    int central_n[52],central_s[52];
public:
    void setvalue();
    void shuffle();
    void dealcard();
    int findfirst();
    void player1_move();
    void player2_move();
    void player3_move();
    void user_choose();
    void print_card(int *,int *);
    void print_cover_card(int *,int *);
    void print_central_card();
    int check_cover_or_through_out_card(int*,int*);
    void cover_card(int,int*,int*,int*,int*);
    int through_out_card(int,int*,int*);
    void find_winer();
};
