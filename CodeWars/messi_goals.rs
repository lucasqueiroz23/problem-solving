fn goals(la_liga_goals: i32, champions_league_goals: i32, copa_del_rey_goals: i32) -> i32 {
    vec![la_liga_goals, champions_league_goals, copa_del_rey_goals]
        .iter()
        .fold(0, |sum, g| sum + g)
}
