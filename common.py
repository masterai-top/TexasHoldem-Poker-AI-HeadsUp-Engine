'''
通用库
'''

HIGH_CARD = 0 # 高牌
ONE_PAIR = 1 << 7 # 一对
TWO_PAIR = 1 << 8 # 两对
THREE_CARD = 1 << 9# 三张
STRAIGHT = 1 << 10# 顺子
FLUSH = 1 << 11# 同花
FULL_HOUSE = 1 << 12# 葫芦
FOUR_CARD = 1 << 13# 四张
STRAIGHT_FLUSH = 1 << 14# 同花顺
ROYAL_FLUSH = 1 << 15# 皇家同花顺

def is_robot(roleid):
    return roleid < 2000000000


def trans_card(card):
    ranks_map = {
        1: "2",
        2: "3",
        3: "4",
        4: "5",
        5: "6",
        6: "7",
        7: "8",
        8: "9",
        9: "0",
        10: "J",
        11: "Q",
        12: "K",
        13: "A"
    }
    suits_map = {
        1: "C",
        2: "D",
        3: "H",
        4: "S"
    }
    if card["rank"]+1 not in ranks_map or card["suit"]+1 not in suits_map:
        return ""
    return suits_map[card["suit"]+1]+ranks_map[card["rank"]+1]


def trans_action(action):
    action_mapping = {
        0: 'FOLD',
        1: 'CALL',
        2: 'RAISE',
    }
    if action in action_mapping:
        return action_mapping[action]
    return ''


def bet_of_pot(bet, player_bet):
    '''
    下注是几倍底池
    '''
    max_bet = max(list(player_bet.values()))
    pot = max_bet * len(player_bet)
    return (bet-max_bet)/pot


def top_pair(hole_card, pub_cards):
    '''
    判断牌力范围
    '''
    pub_cards_number = [card['rank'] for card in pub_cards]
    return max(pub_cards_number)

def is_bluff(hole_card, pub_cards):
    style,_ = card_style(hole_card, pub_cards)
    if style == 'high_card':
        return True
    if style == 'one_pair':
        toppair = top_pair(hole_card, pub_cards)
        pubs = [card['rank'] for card in pub_cards if toppair==card['rank']]
        if len(pubs)>1:
            return True
        cards = hole_card + pub_cards
        card_counts = {}
        for card in cards:
            if card['rank'] not in card_counts:
                card_counts[card['rank']] = 0
            card_counts[card['rank']] += 1
        for card, count in card_counts.items():
            if count == 2 and card == toppair:
                return False
            if count == 2 and card > toppair:
                return False
        return True
    style1,_ = card_style([], pub_cards)
    if style1 != style:
        return False
    return cards_compare(hole_card,[],pub_cards)!=1


def top_pair_compare(hole_card, pub_cards):
    '''
     1  大于
     0  等于
    -1  小于
    '''
    style,_ = card_style(hole_card, pub_cards)
    if style == 'high_card':
        return -1
    if style == 'one_pair':
        toppair = top_pair(hole_card, pub_cards)
        cards = hole_card + pub_cards
        card_counts = {}
        for card in cards:
            if card['rank'] not in card_counts:
                card_counts[card['rank']] = 0
            card_counts[card['rank']] += 1
        for card, count in card_counts.items():
            if count == 2 and card == toppair:
                return 0
            if count == 2 and card > toppair:
                return 1
        return -1
    return 1


def card_style(hole_card, pub_cards):
    '''
    判断牌型
    '''
    style=0
    cards = hole_card + pub_cards
    card_number = [card['rank'] for card in cards]
    if len(card_number) < 5:
        return "",style

    if 12 in card_number:
        card_number.append(-1)
    
    card_number.sort()
    # 判断顺子
    idx = 0
    flush = []
    card_number_no_repeat = list(set(card_number))
    while idx <= len(card_number_no_repeat)-5:
        if card_number_no_repeat[idx+4] - card_number_no_repeat[idx] == 4:
            flush = card_number_no_repeat[idx:idx+5]
        idx += 1
    # print(flush)
    if len(flush) > 0:
        suits = {}
        for card in cards:
            if card['rank'] in flush:
                if card['suit'] not in suits:
                    suits[card['suit']] = 0
                suits[card['suit']] += 1
        if 5 in list(suits.values()):
            if flush[4] == 12:
                return 'royal_flush',ROYAL_FLUSH << 16
            else:
                return 'straight_flush',(STRAIGHT_FLUSH << 16) + (flush[4])
    card_counts = {}
    for rank in card_number:
        if rank not in card_counts:
            card_counts[rank] = 0
        card_counts[rank] += 1
    counts = list(card_counts.values())
    if 4 in counts:
        card = [k for k,v in card_counts.items() if v==4]
        return 'four_of_a_kind',(FOUR_CARD  << 16) + card[0]
    if 3 in counts:
        if 2 in counts or len([c for c in counts if c==3 ]) > 1:
            card3 = [k for k,v in card_counts.items() if v==3]
            card2 = [k for k,v in card_counts.items() if v==2]
            if len(card3) > 1:
                card2 = card2 + [k for k in card3 if k != max(card3)]
                card3 = [k for k in card3 if k == max(card3)]
            return 'full_house',(FULL_HOUSE << 16)+(card3[0] << 4) + card2[0] 
    suits = {}
    for card in cards:
        if card['suit'] not in suits:
            suits[card['suit']] = 0
        suits[card['suit']] += 1
    if 5 in list(suits.values()) or 6 in list(suits.values()) or 7 in list(suits.values()):
        max_suit = max(list(suits.values()))
        card = [c['rank'] for c in cards if c['suit'] in [k for k,v in suits.items() if v==max_suit]]
        card.sort(reverse=True)
        return 'flush',(FLUSH<<16)+(card[0]<<16)+(card[1]<<12)+(card[2]<<8)+(card[3]<<4)+card[4]
    if len(flush) > 0:
        return 'straight',(STRAIGHT << 16) + flush[4]
    if 3 in counts:
        card3 = [k for k,v in card_counts.items() if v==3]
        card_other = [k for k,v in card_counts.items() if v!=3]
        card_other.sort(reverse=True)
        return 'three_of_a_kind',(THREE_CARD <<16) + (card3[0]<<8)+ (card_other[0]<<4)+ card_other[1]
    if 2 in counts:
        if len([i for i in counts if i >= 2]) >= 2:
            card2 = list(set([k for k,v in card_counts.items() if v>=2]))
            card2.sort(reverse=True)
            card_other = [k for k,v in card_counts.items() if v<2]
            if len(card2) > 2:
                card_other.append(card2[2])
                card_other.append(card2[2])
            card_other.sort(reverse=True)
            return 'two_pairs',(TWO_PAIR << 16) + (card2[0]<<8)+ (card2[1]<<4)+card_other[0]
        else:
            card_pair = list(set([k for k,v in card_counts.items() if v>=2]))
            card_other = [k for k,v in card_counts.items() if v<2]
            card_other.sort(reverse=True)
            #print(card_counts)
            return 'one_pair',(ONE_PAIR << 16)+(card_pair[0]<<12)+(card_other[0]<<8)+(card_other[1]<<4)+card_other[2]
    card_other = [k for k,v in card_counts.items()]
    card_other.sort(reverse=True)
    return 'high_card',(HIGH_CARD << 16) +( card_other[0]<< 16)+ (card_other[1]<< 12)+ (card_other[2]<< 8)+ (card_other[3]<< 4)+ card_other[4]


def cards_compare(hole_card1, hole_card2, pub_cards):
    '''
     1  大于
     0  等于
    -1  小于
    '''
    style_mapping = {
        "high_card": 1,
        "one_pair": 2,
        "two_pairs": 3,
        "three_of_a_kind": 4,
        "straight": 5,
        "flush": 6,
        "full_house": 7,
        "four_of_a_kind": 8,
        "straight_flush": 9,
        "royal_flush": 10,
    }
    style1,strength1 = card_style(hole_card1, pub_cards)
    style2,strength2 = card_style(hole_card2, pub_cards)
    if strength1 > strength2:
        return 1
    if strength1 < strength2:
        return -1
    return 0
    
    
    

