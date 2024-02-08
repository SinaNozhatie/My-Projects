from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)

tasks = [
    {"id": 1, "title": "Task 1", "description": "Description 1", "status": "To Do"},
    {"id": 2, "title": "Task 2", "description": "Description 2", "status": "In Progress"},
]

@app.route('/')
def index():
    return render_template('index.html', tasks=tasks)

@app.route('/add', methods=['POST'])
def add_task():
    title = request.form.get('title')
    description = request.form.get('description')
    status = request.form.get('status')

    new_task = {
        "id": len(tasks) + 1,
        "title": title,
        "description": description,
        "status": status,
    }
    tasks.append(new_task)

    return redirect(url_for('index'))

@app.route('/edit/<int:task_id>')
def edit_task(task_id):
    task = next((t for t in tasks if t['id'] == task_id), None)
    return render_template('edit.html', task=task)

@app.route('/update/<int:task_id>', methods=['POST'])
def update_task(task_id):
    task = next((t for t in tasks if t['id'] == task_id), None)

    task['title'] = request.form.get('title')
    task['description'] = request.form.get('description')
    task['status'] = request.form.get('status')

    return redirect(url_for('index'))

@app.route('/delete/<int:task_id>')
def delete_task(task_id):
    global tasks
    tasks = [t for t in tasks if t['id'] != task_id]
    return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(debug=True)
