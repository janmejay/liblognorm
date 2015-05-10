# added 2015-05-10 by singh.janmejay
# This file is part of the liblognorm project, released under ASL 2.0
source ./exec.sh $0 "behaviour of parser with an all-litteral rule among others with fields"

add_rule 'rule=:%foo:char-sep:|%|%bar:char-sep:|%|%baz:char-sep:|%'
execute 'foo|bar|baz'
assert_output_json_eq '{ "baz": "baz", "bar": "bar", "foo": "foo" }'

reset_rules
add_rule 'rule=:foo bar baz'
execute 'foo bar baz'
assert_output_json_eq '{ }'

reset_rules
add_rule 'rule=:%foo:char-sep:|%|%bar:char-sep:|%|%baz:char-sep:|%'
add_rule 'rule=:foo bar baz'
execute 'foo|bar|baz'
assert_output_json_eq '{ "baz": "baz", "bar": "bar", "foo": "foo" }'
execute 'foo bar baz'
assert_output_json_eq '{ }'

reset_rules
add_rule 'rule=:foo bar baz'
add_rule 'rule=:%foo:char-sep:|%|%bar:char-sep:|%|%baz:char-sep:|%'
execute 'foo|bar|baz'
assert_output_json_eq '{ "baz": "baz", "bar": "bar", "foo": "foo" }'
execute 'foo bar baz'
assert_output_json_eq '{ }'
