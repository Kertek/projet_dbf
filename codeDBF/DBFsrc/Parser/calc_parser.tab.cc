// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "/home/menguy/Documents/Etudes/CASSIOPEE/projet_dbf/codeDBF/DBFsrc/Parser/calc_parser.tab.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "calc_parser.tab.hh"

// User implementation prologue.

#line 51 "/home/menguy/Documents/Etudes/CASSIOPEE/projet_dbf/codeDBF/DBFsrc/Parser/calc_parser.tab.cc" // lalr1.cc:407
// Unqualified %code blocks.
#line 28 "DBFsrc/Parser/calc_parser.yy" // lalr1.cc:408

#include <iostream>
#include <cstdlib>
#include <fstream>

/* include for all driver functions */
#include "calc_driver.h"

#undef yylex
#define yylex scanner.yylex

#line 65 "/home/menguy/Documents/Etudes/CASSIOPEE/projet_dbf/codeDBF/DBFsrc/Parser/calc_parser.tab.cc" // lalr1.cc:408


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "DBFsrc/Parser/calc_parser.yy" // lalr1.cc:474
namespace CALC {
#line 151 "/home/menguy/Documents/Etudes/CASSIOPEE/projet_dbf/codeDBF/DBFsrc/Parser/calc_parser.tab.cc" // lalr1.cc:474

  /// Build a parser object.
  CALC_Parser::CALC_Parser (CALC_Scanner  &scanner_yyarg, CALC_Driver  &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  CALC_Parser::~CALC_Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  CALC_Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  CALC_Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  CALC_Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      default:
        break;
    }

  }


  template <typename Base>
  inline
  CALC_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  CALC_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}


  template <typename Base>
  inline
  CALC_Parser::basic_symbol<Base>::~basic_symbol ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      default:
        break;
    }

  }

  template <typename Base>
  inline
  void
  CALC_Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  CALC_Parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  CALC_Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  CALC_Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  CALC_Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  CALC_Parser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  CALC_Parser::symbol_type
  CALC_Parser::make_SELECT (const location_type& l)
  {
    return symbol_type (token::SELECT, l);
  }

  CALC_Parser::symbol_type
  CALC_Parser::make_FIELD (const location_type& l)
  {
    return symbol_type (token::FIELD, l);
  }

  CALC_Parser::symbol_type
  CALC_Parser::make_CHAR (const location_type& l)
  {
    return symbol_type (token::CHAR, l);
  }

  CALC_Parser::symbol_type
  CALC_Parser::make_FROM (const location_type& l)
  {
    return symbol_type (token::FROM, l);
  }

  CALC_Parser::symbol_type
  CALC_Parser::make_WHERE (const location_type& l)
  {
    return symbol_type (token::WHERE, l);
  }

  CALC_Parser::symbol_type
  CALC_Parser::make_COMPARAISON (const location_type& l)
  {
    return symbol_type (token::COMPARAISON, l);
  }

  CALC_Parser::symbol_type
  CALC_Parser::make_LOGIQUE (const location_type& l)
  {
    return symbol_type (token::LOGIQUE, l);
  }

  CALC_Parser::symbol_type
  CALC_Parser::make_AS (const location_type& l)
  {
    return symbol_type (token::AS, l);
  }

  CALC_Parser::symbol_type
  CALC_Parser::make_END (const location_type& l)
  {
    return symbol_type (token::END, l);
  }

  CALC_Parser::symbol_type
  CALC_Parser::make_COMMENT (const location_type& l)
  {
    return symbol_type (token::COMMENT, l);
  }

  CALC_Parser::symbol_type
  CALC_Parser::make_FORBBIDEN (const location_type& l)
  {
    return symbol_type (token::FORBBIDEN, l);
  }



  // by_state.
  inline
  CALC_Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  CALC_Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  CALC_Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  CALC_Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  CALC_Parser::symbol_number_type
  CALC_Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  CALC_Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  CALC_Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      default:
        break;
    }

    // that is emptied.
    that.type = empty;
  }

  inline
  CALC_Parser::stack_symbol_type&
  CALC_Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  CALC_Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  CALC_Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  CALC_Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  CALC_Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  CALC_Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  CALC_Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  CALC_Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  CALC_Parser::debug_level_type
  CALC_Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  CALC_Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline CALC_Parser::state_type
  CALC_Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  CALC_Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  CALC_Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  CALC_Parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 59 "DBFsrc/Parser/calc_parser.yy" // lalr1.cc:847
    {
        printf("commande valide\n");
        YYACCEPT;
        }
#line 672 "/home/menguy/Documents/Etudes/CASSIOPEE/projet_dbf/codeDBF/DBFsrc/Parser/calc_parser.tab.cc" // lalr1.cc:847
    break;

  case 3:
#line 64 "DBFsrc/Parser/calc_parser.yy" // lalr1.cc:847
    {
        printf("commande valide\n");
        YYACCEPT;
        }
#line 681 "/home/menguy/Documents/Etudes/CASSIOPEE/projet_dbf/codeDBF/DBFsrc/Parser/calc_parser.tab.cc" // lalr1.cc:847
    break;


#line 685 "/home/menguy/Documents/Etudes/CASSIOPEE/projet_dbf/codeDBF/DBFsrc/Parser/calc_parser.tab.cc" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  CALC_Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  CALC_Parser::yysyntax_error_ (state_type, symbol_number_type) const
  {
    return YY_("syntax error");
  }


  const signed char CALC_Parser::yypact_ninf_ = -9;

  const signed char CALC_Parser::yytable_ninf_ = -1;

  const signed char
  CALC_Parser::yypact_[] =
  {
       6,    -3,    10,     0,     8,    -9,     6,     7,     5,    -9,
       9,     3,     4,     1,     2,    -9,    -9,    -9,    -9,    -9,
      12,     6,    16,    -9,    21,    11,    -1,    -9,    -9,    18,
       6,    -9,    -9,    22,    25,    15,    -1,    -9,    -9,    17,
      -1,    -9
  };

  const unsigned char
  CALC_Parser::yydefact_[] =
  {
       0,     0,     0,     0,    10,     5,     0,     0,     7,     1,
       2,     0,     0,     0,     0,     3,    18,    19,     9,     8,
      13,     0,    14,     6,     0,     0,     0,     4,    12,     0,
       0,    15,    20,     0,     0,     0,     0,    11,    21,    17,
       0,    16
  };

  const signed char
  CALC_Parser::yypgoto_[] =
  {
      -9,    -9,    -6,    19,    -9,    -9,    -9,    -8,    23,    13
  };

  const signed char
  CALC_Parser::yydefgoto_[] =
  {
      -1,     2,     3,     7,     8,    22,    27,    31,    32,    33
  };

  const unsigned char
  CALC_Parser::yytable_[] =
  {
      12,     4,     5,    16,    17,    20,     4,    16,    17,     1,
       9,    10,     6,    13,    30,    25,    21,     6,    11,    14,
      19,    15,    24,    26,    35,    28,    40,    29,    34,    37,
      36,    38,    41,    23,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39
  };

  const signed char
  CALC_Parser::yycheck_[] =
  {
       6,     4,     5,     4,     5,     4,     4,     4,     5,     3,
       0,    11,    15,     6,    15,    21,    15,    15,    10,    14,
      16,    12,    10,     7,    30,     4,     9,    16,    10,     4,
       8,    16,    40,    14,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36
  };

  const unsigned char
  CALC_Parser::yystos_[] =
  {
       0,     3,    18,    19,     4,     5,    15,    20,    21,     0,
      11,    10,    19,     6,    14,    12,     4,     5,    25,    16,
       4,    15,    22,    20,    10,    19,     7,    23,     4,    16,
      15,    24,    25,    26,    10,    19,     8,     4,    16,    26,
       9,    24
  };

  const unsigned char
  CALC_Parser::yyr1_[] =
  {
       0,    17,    18,    18,    19,    19,    20,    20,    21,    21,
      21,    22,    22,    22,    23,    23,    24,    24,    25,    25,
      26,    26
  };

  const unsigned char
  CALC_Parser::yyr2_[] =
  {
       0,     2,     2,     3,     5,     2,     3,     1,     3,     3,
       1,     5,     3,     1,     0,     2,     5,     3,     1,     1,
       1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const CALC_Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "SELECT", "FIELD", "CHAR", "FROM",
  "WHERE", "COMPARAISON", "LOGIQUE", "AS", "END", "COMMENT", "FORBBIDEN",
  "','", "'('", "')'", "$accept", "commands", "command", "selection",
  "ssrecherche", "provenance", "condition_close", "condition",
  "field_ou_char", "field_ou_char_ou_command", YY_NULLPTR
  };


  const unsigned char
  CALC_Parser::yyrline_[] =
  {
       0,    58,    58,    63,    70,    70,    73,    73,    76,    77,
      78,    81,    82,    83,    86,    87,    90,    91,    94,    95,
      98,    99
  };

  // Print the state stack on the debug stream.
  void
  CALC_Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  CALC_Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  CALC_Parser::token_number_type
  CALC_Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      15,    16,     2,     2,    14,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13
    };
    const unsigned int user_token_number_max_ = 268;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "DBFsrc/Parser/calc_parser.yy" // lalr1.cc:1155
} // CALC
#line 1036 "/home/menguy/Documents/Etudes/CASSIOPEE/projet_dbf/codeDBF/DBFsrc/Parser/calc_parser.tab.cc" // lalr1.cc:1155
#line 101 "DBFsrc/Parser/calc_parser.yy" // lalr1.cc:1156



void
CALC::CALC_Parser::error( const location_type &l, const std::string &err_message )
{
    std::cerr << "Error: " << err_message << " at " << l << "\n";
}
