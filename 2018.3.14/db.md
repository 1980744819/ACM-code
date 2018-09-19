##数据表设计

###1.用户表Users
 用于验证用户登陆，以及对当前页面是否有管理权限
  | 列| id | user_id | nick_name | password |
  |:--|:----|:---------|:---------|:---------|
  |说明 | 主键|用户编号 | 昵称 |密码 |
  | 类型|Integer |String(10) |Unicode(32) |String(32) |  


###2.设置菜单标题Menu_name
页面标题的描述以及标题的编号
|列|title|description|id|question_num|
|:--|:--|:--|:--|:--|
|说明|设置菜单标题|描述|编号,主键|问题数量|
|类型|Unicode(32)|String(32)|Integer|Integer|

###3.用户管理权限表Manage
|列|id|menu_name_id|manage_person_id|
|:--|:--|:--|:--|
|说明|主键|菜单标题编号|管理人员的编号|
|类型|Integer|Integer|Integer|

###4.当前菜单问题表Survey_questions
|列|question|answerType|question_id|belongs_to_id|
|:--|:--|:--|:--|:--|
|说明|问题描述|答案类型(单选，多选，填空)|问题编号|所属菜单id|
|类型|String(32)|Integer(0表示单选，1表示多选，2表示填空)|Integer|Integer|

###5.用户选择设置保存表
|列|id|user_id|menu_id|question_id|answer|
|:--|:--|:--|:--|:--|:--|:--|
|说明|主键|用户编号|菜单标题编号|问题编号|答案|
|类型|Integer|Integer|Integer|Integer|


###6.用户填空设置保存表
|列|id|user_id|menu_id|question_id|answer|
|:--|:--|:--|:--|:--|:--|:--|
|说明|主键|用户编号|菜单标题编号|问题编号|答案|
|类型|Integer|Integer|Integer|String(32)|

###7.用户问卷标题表
|列|id|user_id|menu_id|
|:--|:--|:--|:--|
|说明|主键|用户id|菜单标题id|
|类型|Integer|Integer|Integer|



##说明
类似于问卷调查
用户登陆，Users表用于验证用户登陆，用户权限管理表用于验证，用户是否可以管理当前问卷，然后从当前菜单表找到各个问题，作为表单显示在网页上，然后用户选择各个问题的答案，提交，选择题和填空答案分别保存在用户选择设置保存表和用户填空设置保存表，查找该用户的设置时,通过菜单标题表找到设置隐私的问卷编号,然后分别在用户选择保存表和用户填空保存表中找到设置的答案，一问题编号升序的形式展现出来。