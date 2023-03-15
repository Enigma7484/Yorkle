#pragma once

#define WORD_SIZE 5
#define MAX_NUM_ATTEMPTS 6
#define MAX_VALID_WORDS 20000

typedef enum {
  LR_INCORRECT = 0,
  LR_WRONG_PLACE,
  LR_IN_PLACE
} letter_result_t;

typedef struct valid_word_list {

  /** Array containing a list of all words accepted as guesses in the
      game. Only the first `num_words` words are considered. */
  char words[MAX_VALID_WORDS][WORD_SIZE + 1];

  /** Number of items in `words` that correspond to a valid word. */
  unsigned int num_words;
} valid_word_list_t;

typedef struct player_stats {
  /** Number of games in which the player has correctly guessed the
      word after 1, 2, 3, ... guess attempts. Note that indices start
      at zero, so `stats_per_num_attempts[i]` corresponds to the
      number of games where `i+1` attempts were needed. */
  unsigned int wins_per_num_attempts[MAX_NUM_ATTEMPTS];

  /** Number of games in which the player was unable to guess the
      correct word even after MAX_NUM_ATTEMPTS guesses. */
  unsigned int num_missed_words;
} player_stats_t;

int load_valid_words(valid_word_list_t *);
int load_todays_answer(char[]);

int read_attempt(unsigned int, char[]);
int attempt_is_valid(const valid_word_list_t *, const char[]);

int compare_result(const char[], const char[], letter_result_t[]);
void print_attempt_result(const char[], const letter_result_t[]);

void load_stats(player_stats_t *);
int save_stats(player_stats_t *, unsigned int);
void print_stats(const player_stats_t *);
